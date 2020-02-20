#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /Applications/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source;/Applications/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/kernel/tirtos/packages
override XDCROOT = /Applications/ti/ccs920/xdctools_3_60_01_27_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /Applications/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source;/Applications/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/kernel/tirtos/packages;/Applications/ti/ccs920/xdctools_3_60_01_27_core/packages;..
HOSTOS = MacOS
endif
