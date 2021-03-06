/*
 *  ======== ti_radio_config.h ========
 *  Configured RadioConfig module definitions
 *
 *  DO NOT EDIT - This file is generated for the CC2652R1FRGZ
 *  by the SysConfig tool.
 *  
 *  Radio Config module version : 1.3
 *  SmartRF Studio data version : 2.15.0
 */
#ifndef _TI_RADIO_CONFIG_H_
#define _TI_RADIO_CONFIG_H_

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/rf_mailbox.h)
#include DeviceFamily_constructPath(driverlib/rf_common_cmd.h)
#include DeviceFamily_constructPath(driverlib/rf_ieee_cmd.h)
#include <ti/drivers/rf/RF.h>


//*********************************************************************************
//  RF Setting:   IEEE 802.15.4 O-QPSK DSSS PHY (250 kbps) at 2450 MHz band
//
//  PHY:          ieee154     
//  Setting file: setting_ieee_802_15_4.json
//*********************************************************************************

// TX Power table size definition
#define TX_POWER_TABLE_SIZE_ieee154 11

// TX Power Table Object
extern RF_TxPowerTable_Entry txPowerTable_ieee154[];

// TI-RTOS RF Mode Object
extern RF_Mode RF_prop_ieee154;

// RF Core API commands
extern const rfc_CMD_RADIO_SETUP_t RF_cmdRadioSetup_ieee154;
extern const rfc_CMD_FS_t RF_cmdFs_ieee154;
extern const rfc_CMD_IEEE_TX_t RF_cmdIeeeTx_ieee154;
extern const rfc_CMD_IEEE_RX_t RF_cmdIeeeRx_ieee154;
extern const rfc_CMD_IEEE_CSMA_t RF_cmdIeeeCsma_ieee154;
extern const rfc_CMD_IEEE_RX_ACK_t RF_cmdIeeeRxAck_ieee154;

// RF Core API Overrides
extern uint32_t pOverrides_ieee154[];

#endif // _TI_RADIO_CONFIG_H_
