################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Stack/af/%.obj: ../Stack/af/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" --cmd_file="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/Config/f8wcoord.opts"  -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O4 --opt_for_speed=0 --include_path="C:/Users/jheer/git/senior_design_iot_zigbee" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/default" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Application/StartUp" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Application/Services" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Application/ui" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Application/util" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Application/ZStackApi" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Common/gp" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Common/touchlink" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/af" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/bdb" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/Config" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/gp" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/HAL/Assert" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/HAL/Appasrt" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/HAL/Crypto" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/HAL/Platform" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/HAL/RF" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/MAC/HighLevel" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/MAC/LowLevel" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/MAC" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/nwk" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/osal_port" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/ROM" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/sec" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/sys" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/zdo" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/zmac" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Stack/ZStackTask" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/mt" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/osal" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/services/saddr" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/services/sdata" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/assert" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/appasrt" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/crypto" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/platform" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/rf" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/af" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/bdb" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/bdb/touchlinkapp" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/gp" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/api" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/nwk" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/sec" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/sys" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/zcl" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/zdo" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/zmac" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/zmac/f8w" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/stack/ui" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/common/cui" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/fh" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/high_level" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/inc/cc13xx" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/low_level/cc13xx" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/tracer" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/rom" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/heapmgr" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/osal_port" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/osal_port/osal_port_tirtos" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/common/nv" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/util" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/util" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/config" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/startup" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/api/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/devices/cc13x2_cc26x2" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/devices/cc13x2_cc26x2/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/devices/cc13x2_cc26x2/driverlib" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/zstack/apps/thermostat" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/Common/zcl" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/boards" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/posix/ccs" --define=ZCL_READ --define=ZCL_DISCOVER --define=ZCL_WRITE --define=ZCL_BASIC --define=ZCL_IDENTIFY --define=ZCL_HVAC_CLUSTER --define=BDB_REPORTING --define=ZCL_REPORT_DESTINATION_DEVICE --define=TIMAC_ROM_IMAGE_BUILD --define=TIMAC_ROM_PATCH --define=USE_ZCL_SAMPLEAPP_UI --define=MAX_STATUS_LINES=10 --define=ZSTACK_AESECB --define=BOARD_DISPLAY_USE_UART --define=FREQ_2_4G --define=OSAL_PORT2TIRTOS --define=OSAL_PORT2TIRTOS_OSALMAP --define=RCN_APP_ASSERT --define=HAL_ASSERT_SPIN --define=ZDO_API_BASIC --define=TC_LINKKEY_JOIN --define=NV_RESTORE --define=NV_INIT --define=FEATURE_NON_BEACON_MODE --define=ZCL_STANDALONE --define=MAX_DEVICE_TABLE_ENTRIES=50 --define=NVOCMP_NVPAGES=2 --define=DEVICE_FAMILY=cc26x0 --define=CC26X2R1_LAUNCHXL --define=DeviceFamily_CC26X2 -g --c99 --plain_char=unsigned --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --embedded_constants=on --unaligned_access=on --enum_type=packed --wchar_t=16 --abi=eabi --common=on --fp_reassoc=off --sat_reassoc=off --preproc_with_compile --preproc_dependency="Stack/af/$(basename $(<F)).d_raw" --include_path="C:/Users/jheer/git/senior_design_iot_zigbee/default/syscfg" --obj_directory="Stack/af" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


