/**************************************************************************************************
  Filename:       zcl_retail.h
  Revised:        $Date: 2018-22-11 10:12:34 -0700 (Thur, 22 Nov 2018) $
  Revision:       $Revision: 25678 $

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

#ifndef ZCL_RETAIL_H
#define ZCL_RETAIL_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include "zcl.h"


/*********************************************************************
 * CONSTANTS
 */

/**********************************************/
/*** Retail Tunnel Clusters Attributes List ***/
/**********************************************/
#define ATTRID_RETAIL_TUNNEL_MANUFACTURER_CODE        0x0000
#define ATTRID_RETAIL_TUNNEL_MSPROFILE                0x0001

/**********************************************/
/*** Mobile Device Clusters Attributes List ***/
/**********************************************/
#define ATTRID_RETAIL_MOBILE_KEEP_ALIVE_TIME          0x0000
#define ATTRID_RETAIL_MOBILE_REJOIN_TIMEOUT           0x0001

/**************************************************/
/*** Neighbor Cleaning Clusters Attributes List ***/
/**************************************************/
#define ATTRID_RETAIL_NEIGHBOR_CLEANING_TIMEOUT       0x0000

/************************************************/
/*** Nearest Gateway Clusters Attributes List ***/
/************************************************/
#define ATTRID_RETAIL_NEAREST_GW_NEAREST_GW           0x0000
#define ATTRID_RETAIL_NEAREST_GW_NEW_MOBILE_NODE      0x0001

/*************************************/
/***Retail Tunnel Cluster Commands ***/
/*************************************/
// Commands Received by Retail tunnel Cluster Server
#define COMMAND_ID_RETAIL_TUNNEL_TRANSFER_APDU              0x00


/****************************************/
/***  Mobile Device Cluster Commands  ***/
/****************************************/
// Commands Received by Mobile Device Cluster Server
#define COMMAND_ID_RETAIL_MOBILE_KEEP_ALIVE_NOTI            0x00


/***********************************************/
/***    Neighbor Cleaning Cluster Commands   ***/
/***********************************************/
// Commands Received by Neighbor Cleaning Cluster Server
#define COMMAND_ID_RETAIL_NEIGHBOR_PURGE_ENTRIES            0x00

/******************************************************************/
/***        Other Constants                                     ***/
/******************************************************************/




/********************************************************************
 * MACROS
 */


/*********************************************************************
 * TYPEDEFS
 */

/*** Structures used for callback functions ***/

typedef struct
{
    afAddrType_t *srcAddr;  // requestor's address
    uint8_t *apdu;            // retail tunnel APDU
}zclRetailTunnelTransferAPDU_t;

typedef struct
{
    afAddrType_t *srcAddr;  // requestor's address
    uint16_t keepAliveTime;
    uint16_t rejoinTimeout;

}zclMobileDeviceConfigurationKeepAliveNotification_t;

typedef struct
{
    afAddrType_t *srcAddr;  // requestor's address
}zclNeighborCleaningPurgeEntries_t;


typedef void (*zclPICB_RetailTunnelTransferAPDU_t)( zclRetailTunnelTransferAPDU_t *pCmd );

typedef void (*zclPICB_MobileDeviceConfigurationKeepAliveNotification_t)( zclMobileDeviceConfigurationKeepAliveNotification_t *pCmd );

typedef void (*zclPICB_NeighborCleaningPurgeEntries_t)( zclNeighborCleaningPurgeEntries_t *pCmd );


typedef struct
{
    zclPICB_RetailTunnelTransferAPDU_t           pfnPI_RetailTunnelTransferAPDU;
}zclPIRetail_AppCallbacks_t;

typedef struct
{
    zclPICB_MobileDeviceConfigurationKeepAliveNotification_t    pfnPI_MobileDeviceConfigurationKeepAliveNotification;
    zclPICB_NeighborCleaningPurgeEntries_t                      pfnPI_NeighborCleaningPurgeEntries;
}zclRetailCluster_AppCallbacks_t;


/*********************************************************************
 * CALLBACKS
 */

/*********************************************************************
 * VARIABLES
 */

/*********************************************************************
 * FUNCTION MACROS
 */


/*********************************************************************
 * FUNCTIONS
 */

extern ZStatus_t zclRetailCluster_RegisterCmdCallbacks( uint8_t endpoint, zclRetailCluster_AppCallbacks_t *callbacks );

extern ZStatus_t zclPIRetailTunnel_RegisterCmdCallbacks( uint8_t endpoint, zclPIRetail_AppCallbacks_t *callbacks );
extern ZStatus_t zclRetailCluster_RegisterCmdCallbacks( uint8_t endpoint, zclRetailCluster_AppCallbacks_t *callbacks );
extern ZStatus_t zclPI_Send_RetailTunnelTransferAPDUCmd( uint8_t srcEP, afAddrType_t *dstAddr, zclFrameHdr_t *hdr,
                                           uint8_t len, uint8_t *apdu, uint8_t seqNum );

#ifdef __cplusplus
}
#endif

#endif /* ZCL_RETAIL_H */
