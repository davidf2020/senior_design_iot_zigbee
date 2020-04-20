# invoke SourceDir generated makefile for app.pem4f
app.pem4f: .libraries,app.pem4f
.libraries,app.pem4f: package/cfg/app_pem4f.xdl
	$(MAKE) -f /Users/davidfernandez/workspace_v9/i19_zc_thermostat_CC26X2R1_LAUNCHXL_tirtos_ccs/src/makefile.libs

clean::
	$(MAKE) -f /Users/davidfernandez/workspace_v9/i19_zc_thermostat_CC26X2R1_LAUNCHXL_tirtos_ccs/src/makefile.libs clean

