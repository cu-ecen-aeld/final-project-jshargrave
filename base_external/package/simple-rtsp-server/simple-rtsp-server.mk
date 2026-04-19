
##############################################################
#
# SIMPLE-RTSP-SERVER
#
##############################################################

SIMPLE_RTSP_SERVER_VERSION = 1.0
SIMPLE_RTSP_SERVER_SITE = $(BR2_EXTERNAL)/package/simple-rtsp-server
SIMPLE_RTSP_SERVER_SITE_METHOD = local

define SIMPLE_RTSP_SERVER_BUILD_CMDS
	$(TARGET_CC) $(@D)/simple-rtsp-server.c -o $(@D)/simple-rtsp-server \
		$(shell $(PKG_CONFIG_HOST_BINARY) --cflags --libs gstreamer-rtsp-server-1.0)
endef

define SIMPLE_RTSP_SERVER_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/simple-rtsp-server $(TARGET_DIR)/usr/bin/simple-rtsp-server
endef

$(eval $(generic-package))
