#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>

int main(int argc, char *argv[]) {
    GMainLoop *loop;
    GstRTSPServer *server;
    GstRTSPMountPoints *mounts;
    GstRTSPMediaFactory *factory;

    gst_init(&argc, &argv);

    loop = g_main_loop_new(NULL, FALSE);
    server = gst_rtsp_server_new();
    gst_rtsp_server_set_service(server, "8554");

    mounts = gst_rtsp_server_get_mount_points(server);
    factory = gst_rtsp_media_factory_new();

    gst_rtsp_media_factory_set_launch(
        factory,
        "( v4l2src device=/dev/video0 ! "
        "video/x-raw,format=YUY2,width=640,height=480,framerate=5/1 ! "
        "jpegenc ! rtpjpegpay name=pay0 pt=26 )"
    );
    gst_rtsp_media_factory_set_shared(factory, TRUE);

    gst_rtsp_mount_points_add_factory(mounts, "/rpi", factory);
    g_object_unref(mounts);

    gst_rtsp_server_attach(server, NULL);
    g_print("stream ready at rtsp://127.0.0.1:8554/rpi\n");

    g_main_loop_run(loop);
    return 0;
}