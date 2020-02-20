/**************************************************************************************************
  Filename:       zcl_retail.c
  Revised:        $Date: 2018-22-11 13:53:09 -0700 (Thur, 22 Nov 2018) $
  Revision:       $Revision: 34523 $

  Description:    Zigbee Cluster Library - Retail Services Cluster


  Copyright 2011 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/


/*********************************************************************
 * INCLUDES
 */
#include "zcl.h"
#include "zcl_general.h"
#include "zcl_retail.h"

#if defined ( INTER_PAN ) || defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  #include "stub_aps.h"
#endif

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * TYPEDEFS
 */



typedef struct zclPIRetailCBRec
{
  struct zclPIRetailCBRec     *next;
  uint8_t                 endpoint; // Used to link it into the endpoint descriptor
  zclPIRetail_AppCallbacks_t  *CBs;     // Pointer to Callback function
} zclPIRetailCBRec_t;

typedef struct zclRetailClusterCBRec
{
  struct zclRetailClusterCBRec     *next;
  uint8_t                 endpoint; // Used to link it into the endpoint descriptor
  zclRetailCluster_AppCallbacks_t  *CBs;     // Pointer to Callback function
} zclRetailClusterCBRec_t;


/*********************************************************************
 * GLOBAL VARIABLES
 */



/*********************************************************************
 * GLOBAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */
static zclPIRetailCBRec_t *zclPIRetailCBs = (zclPIRetailCBRec_t *)NULL;
static zclRetailClusterCBRec_t *zclRetailClusterCBs = (zclRetailClusterCBRec_t *)NULL;

static uint8_t zclPIRetailPluginRegisted = FALSE;
static uint8_t zclRetailClusterPluginRegisted = FALSE;


/*********************************************************************
 * LOCAL FUNCTIONS
 */

static ZStatus_t zclPIRetailTunnel_HdlIncoming( zclIncoming_t *pInHdlrMsg );
static ZStatus_t zclRetailClusterTunnel_HdlIncoming( zclIncoming_t *pInMsg );

static zclPIRetail_AppCallbacks_t *zclPIRetail_FindCallbacks( uint8_t endpoint );
static zclRetailCluster_AppCallbacks_t *zclRetailCluster_FindCallbacks( uint8_t endpoint );

ZStatus_t zclPIRetailTunnel_RegisterCmdCallbacks( uint8_t endpoint, zclPIRetail_AppCallbacks_t *callbacks )
{
    zclPIRetailCBRec_t *pNewItem;
    zclPIRetailCBRec_t *pLoop;

  // Register as a ZCL Plugin
  if ( !zclPIRetailPluginRegisted )
  {
    zcl_registerPlugin( ZCL_CLUSTER_ID_PI_RETAIL_TUNNEL,
                        ZCL_CLUSTER_ID_PI_RETAIL_TUNNEL,
                        zclPIRetailTunnel_HdlIncoming );
    zclPIRetailPluginRegisted = TRUE;
  }

  // Fill in the new profile list
  pNewItem = zcl_mem_alloc( sizeof( zclPIRetailCBRec_t ) );
  if ( pNewItem == NULL )
    return (ZMemError);

  pNewItem->next = (zclPIRetailCBRec_t *)NULL;
  pNewItem->endpoint = endpoint;
  pNewItem->CBs = callbacks;

  // Find spot in list
  if ( zclPIRetailCBs == NULL )
  {
      zclPIRetailCBs = pNewItem;
  }
  else
  {
    // Look for end of list
    pLoop = zclPIRetailCBs;
    while ( pLoop->next != NULL )
      pLoop = pLoop->next;

    // Put new item at end of list
    pLoop->next = pNewItem;
  }
  return ( ZSuccess );
}


ZStatus_t zclRetailCluster_RegisterCmdCallbacks( uint8_t endpoint, zclRetailCluster_AppCallbacks_t *callbacks )
{
    zclRetailClusterCBRec_t *pNewItem;
    zclRetailClusterCBRec_t *pLoop;

  // Register as a ZCL Plugin
  if ( !zclRetailClusterPluginRegisted )
  {
    zcl_registerPlugin( ZCL_CLUSTER_ID_MOBILE_DEVICE_CONFIGURATION,
                        ZCL_CLUSTER_ID_NEIGHBOR_CLEANING,
                        zclRetailClusterTunnel_HdlIncoming );
    zclRetailClusterPluginRegisted = TRUE;
  }

  // Fill in the new profile list
  pNewItem = zcl_mem_alloc( sizeof( zclRetailClusterCBRec_t ) );
  if ( pNewItem == NULL )
    return (ZMemError);

  pNewItem->next = (zclRetailClusterCBRec_t *)NULL;
  pNewItem->endpoint = endpoint;
  pNewItem->CBs = callbacks;

  // Find spot in list
  if ( zclRetailClusterCBs == NULL )
  {
      zclRetailClusterCBs = pNewItem;
  }
  else
  {
    // Look for end of list
    pLoop = zclRetailClusterCBs;
    while ( pLoop->next != NULL )
      pLoop = pLoop->next;

    // Put new item at end of list
    pLoop->next = pNewItem;
  }
  return ( ZSuccess );
}



ZStatus_t zclPI_Send_RetailTunnelTransferAPDUCmd( uint8_t srcEP, afAddrType_t *dstAddr,zclFrameHdr_t *hdr,
                                           uint8_t len, uint8_t *apdu, uint8_t seqNum )
{
  uint8_t *buf;
  ZStatus_t stat;
  buf = zcl_mem_alloc(len); // 2 for length field (long octet string)
  if ( buf )
  {
    buf[0] = len;
    zcl_memcpy( &(buf[1]), apdu, len );

    // This command shall always be transmitted with the Disable Default
    // Response bit in the ZCL frame control field set to 1.
    if(zcl_ServerCmd(hdr->fc.direction)){
        stat = zcl_SendCommand( srcEP, dstAddr, ZCL_CLUSTER_ID_PI_RETAIL_TUNNEL,
                                COMMAND_ID_RETAIL_TUNNEL_TRANSFER_APDU, TRUE,
                                ZCL_FRAME_CLIENT_SERVER_DIR, TRUE, 0, seqNum, (len), buf );
    }
    else {
        stat = zcl_SendCommand( srcEP, dstAddr, ZCL_CLUSTER_ID_PI_RETAIL_TUNNEL,
                                COMMAND_ID_RETAIL_TUNNEL_TRANSFER_APDU, TRUE,
                                ZCL_FRAME_SERVER_CLIENT_DIR, TRUE, 0, seqNum, (len), buf );
    }

    zcl_mem_free( buf );
  }
  else
  {
    stat = ZMemError;
  }

  return ( stat );
}



static zclPIRetail_AppCallbacks_t *zclPIRetail_FindCallbacks( uint8_t endpoint )
{
    zclPIRetailCBRec_t *pCBs;

  pCBs = zclPIRetailCBs;
  while ( pCBs )
  {
    if ( pCBs->endpoint == endpoint )
      return ( pCBs->CBs );
  }
  return ( (zclPIRetail_AppCallbacks_t *)NULL );
}

static zclRetailCluster_AppCallbacks_t *zclRetailCluster_FindCallbacks( uint8_t endpoint )
{
    zclRetailClusterCBRec_t *pCBs;

  pCBs = zclRetailClusterCBs;
  while ( pCBs )
  {
    if ( pCBs->endpoint == endpoint )
      return ( pCBs->CBs );
  }
  return ( (zclRetailCluster_AppCallbacks_t *)NULL );
}


static ZStatus_t zclPIRetailTunnel_HdlIncoming( zclIncoming_t *pInMsg )
{
  ZStatus_t stat = ZSuccess;

#if defined ( INTER_PAN ) || defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  if ( StubAPS_InterPan( pInMsg->msg->srcAddr.panId, pInMsg->msg->srcAddr.endPoint ) )
    return ( stat ); // Cluster not supported thru Inter-PAN
#endif

  if ( zcl_ClusterCmd( pInMsg->hdr.fc.type ) )
  {
    // Is this a manufacturer specific command?
    if ( pInMsg->hdr.fc.manuSpecific == 0 )
    {

        //ZStatus_t stat;
        zclPIRetail_AppCallbacks_t *pCBs;

        // make sure endpoint exists
        pCBs = zclPIRetail_FindCallbacks( pInMsg->msg->endPoint );
        if ( pCBs == NULL )
          return ( ZFailure );

        switch ( pInMsg->msg->clusterId )
        {
            case ZCL_CLUSTER_ID_PI_RETAIL_TUNNEL:
                if ( pCBs->pfnPI_RetailTunnelTransferAPDU )
                {
                    zclRetailTunnelTransferAPDU_t cmd;
                    cmd.srcAddr = &(pInMsg->msg->srcAddr);
                    //cmd.len = BUILD_UINT16( pInMsg->pData[0], pInMsg->pData[1] );
                    cmd.apdu = &(pInMsg->pData[2]);
                    pCBs->pfnPI_RetailTunnelTransferAPDU( &cmd );
                }
          break;

        }//end switch

    }
    else
    {
      // We don't support any manufacturer specific command -- ignore it.
      stat = ZFailure;
    }
  }
  else
  {
    // Handle all the normal (Read, Write...) commands
    stat = ZFailure;
  }

  return ( stat );
}


static ZStatus_t zclRetailClusterTunnel_HdlIncoming( zclIncoming_t *pInMsg )
{
  ZStatus_t stat = ZSuccess;

#if defined ( INTER_PAN ) || defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  if ( StubAPS_InterPan( pInMsg->msg->srcAddr.panId, pInMsg->msg->srcAddr.endPoint ) )
    return ( stat ); // Cluster not supported thru Inter-PAN
#endif

  if ( zcl_ClusterCmd( pInMsg->hdr.fc.type ) )
  {
    // Is this a manufacturer specific command?
    if ( pInMsg->hdr.fc.manuSpecific == 0 )
    {

        //ZStatus_t stat;
        zclRetailCluster_AppCallbacks_t *pCBs;

        // make sure endpoint exists
        pCBs = zclRetailCluster_FindCallbacks( pInMsg->msg->endPoint );
        if ( pCBs == NULL )
          return ( ZFailure );

        switch ( pInMsg->msg->clusterId )
        {
            case ZCL_CLUSTER_ID_MOBILE_DEVICE_CONFIGURATION:
                if ( pCBs->pfnPI_MobileDeviceConfigurationKeepAliveNotification )
                {
                    zclMobileDeviceConfigurationKeepAliveNotification_t cmd;
                    cmd.srcAddr = &(pInMsg->msg->srcAddr);
                    //cmd.len = BUILD_UINT16( pInMsg->pData[0], pInMsg->pData[1] );
                    pCBs->pfnPI_MobileDeviceConfigurationKeepAliveNotification( &cmd );
                }
          break;
            case ZCL_CLUSTER_ID_NEIGHBOR_CLEANING:
                if ( pCBs->pfnPI_NeighborCleaningPurgeEntries )
                {
                    zclNeighborCleaningPurgeEntries_t cmd;
                    cmd.srcAddr = &(pInMsg->msg->srcAddr);
                    //cmd.len = BUILD_UINT16( pInMsg->pData[0], pInMsg->pData[1] );
                    pCBs->pfnPI_NeighborCleaningPurgeEntries( &cmd );
                }
          break;

        }//end switch

    }
    else
    {
      // We don't support any manufacturer specific command -- ignore it.
      stat = ZFailure;
    }
  }
  else
  {
    // Handle all the normal (Read, Write...) commands
    stat = ZFailure;
  }

  return ( stat );
}


/********************************************************************************************
*********************************************************************************************/
