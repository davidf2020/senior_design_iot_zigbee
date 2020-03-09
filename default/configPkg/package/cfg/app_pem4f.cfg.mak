# invoke SourceDir generated makefile for app.pem4f
app.pem4f: .libraries,app.pem4f
.libraries,app.pem4f: package/cfg/app_pem4f.xdl
	$(MAKE) -f C:\Users\jheer\git\senior_design_iot_zigbee/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\jheer\git\senior_design_iot_zigbee/src/makefile.libs clean

