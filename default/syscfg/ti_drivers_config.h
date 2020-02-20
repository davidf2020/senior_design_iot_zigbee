/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the CC26X2R1_LAUNCHXL
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_CC26X2R1_LAUNCHXL

#ifndef DeviceFamily_CC26X2
#define DeviceFamily_CC26X2
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== AESCBC ========
 */

#define CONFIG_AESCBC_0             0


/*
 *  ======== AESCCM ========
 */

#define CONFIG_AESCCM_0             0


/*
 *  ======== AESECB ========
 */

#define CONFIG_AESECB_0             0


/*
 *  ======== ECDH ========
 */

#define CONFIG_ECDH_0               0


/*
 *  ======== ECDSA ========
 */

#define CONFIG_ECDSA_0              0


/*
 *  ======== ECJPAKE ========
 */

#define CONFIG_ECJPAKE_0            0


/*
 *  ======== GPIO ========
 */

/* DIO6, LaunchPad LED Red */
#define CONFIG_GPIO_RLED            0
/* DIO7, LaunchPad LED Green */
#define CONFIG_GPIO_GLED            1
/* DIO13, LaunchPad Button BTN-1 (Left) */
#define CONFIG_GPIO_BTN1            2
/* DIO14, LaunchPad Button BTN-2 (Right) */
#define CONFIG_GPIO_BTN2            3
/* DIO20, MX25R8035F SPI Flash Slave Select */
#define CONFIG_GPIO_0               4

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== NVS ========
 */

#define CONFIG_NVSINTERNAL          0
/*
 *  MOSI: DIO9
 *  MISO: DIO8
 *  SCLK: DIO10
 *  LaunchPad SPI Bus
 *  SS: DIO20, MX25R8035F SPI Flash Slave Select
 */
#define CONFIG_NVSEXTERNAL          1


/*
 *  ======== PIN ========
 */

/* Includes */
#include <ti/drivers/PIN.h>

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* XDS110 UART, Parent Signal: CONFIG_DISPLAY_UART TX, (DIO3) */
#define CONFIG_PIN_UART_TX    0x00000003
/* XDS110 UART, Parent Signal: CONFIG_DISPLAY_UART RX, (DIO2) */
#define CONFIG_PIN_UART_RX    0x00000002
/* LaunchPad LED Red, Parent Signal: CONFIG_GPIO_RLED GPIO Pin, (DIO6) */
#define CONFIG_PIN_RLED    0x00000006
/* LaunchPad LED Green, Parent Signal: CONFIG_GPIO_GLED GPIO Pin, (DIO7) */
#define CONFIG_PIN_GLED    0x00000007
/* LaunchPad Button BTN-1 (Left), Parent Signal: CONFIG_GPIO_BTN1 GPIO Pin, (DIO13) */
#define CONFIG_PIN_BTN1    0x0000000d
/* LaunchPad Button BTN-2 (Right), Parent Signal: CONFIG_GPIO_BTN2 GPIO Pin, (DIO14) */
#define CONFIG_PIN_BTN2    0x0000000e
/* MX25R8035F SPI Flash Slave Select, Parent Signal: CONFIG_GPIO_0 GPIO Pin, (DIO20) */
#define CONFIG_PIN_0    0x00000014
/* LaunchPad SPI Bus, Parent Signal: CONFIG_SPI_0 SCLK, (DIO10) */
#define CONFIG_PIN_SPI_SCLK    0x0000000a
/* LaunchPad SPI Bus, Parent Signal: CONFIG_SPI_0 MISO, (DIO8) */
#define CONFIG_PIN_SPI_MISO    0x00000008
/* LaunchPad SPI Bus, Parent Signal: CONFIG_SPI_0 MOSI, (DIO9) */
#define CONFIG_PIN_SPI_MOSI    0x00000009




/*
 *  ======== SHA2 ========
 */

#define CONFIG_SHA2_0               0


/*
 *  ======== SPI ========
 */

/*
 *  MOSI: DIO9
 *  MISO: DIO8
 *  SCLK: DIO10
 *  LaunchPad SPI Bus
 */
#define CONFIG_SPI_0                0


/*
 *  ======== TRNG ========
 */

#define CONFIG_TRNG_0               0


/*
 *  ======== UART ========
 */

/*
 *  TX: DIO3
 *  RX: DIO2
 *  XDS110 UART
 */
#define CONFIG_DISPLAY_UART         0


/*
 *  ======== Button ========
 */

/* DIO13, LaunchPad Button BTN-1 (Left) */
#define CONFIG_BTN_LEFT             0
/* DIO14, LaunchPad Button BTN-2 (Right) */
#define CONFIG_BTN_RIGHT            1


/*
 *  ======== LED ========
 */

/* DIO6, LaunchPad LED Red */
#define CONFIG_LED_RED              0
/* DIO7, LaunchPad LED Green */
#define CONFIG_LED_GREEN            1


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
