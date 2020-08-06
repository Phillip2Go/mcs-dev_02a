//
// Created by Phillip Mai on 18.03.20.
//

#include "rootstream.h"

/**
 * Rootstream class.
 *
 * Creates an root stream with help of OpenCV API.
 * Reads the root frame from the camera.
 * This root frame only exist once in this project.
 * The root frame is a Singleton.
 * The server internally multiplies the frames by the specified settings.
 *
 */
rootstream::rootstream() {}; // Default constructor

/**
 * Rootstream class starts with constructor.
 *
 * @param get 'rootstreampath' from constructor
 * @param get 'camip' from constructor
 * @param get 'rootfactory' from constructor
 * @param create root stream with given settings
 */
rootstream::rootstream(std::string rootstreampath, std::string camip, GstRTSPMediaFactory  *controllerfactory) {
    this->rootstreampath = rootstreampath;
    this->camip = camip;
    this->rootfactory = controllerfactory;
    this->createrootstream();

    // OpenCV start
    //this->initstream();
}

/**
 * Rootstream creates and retrieves
 * the controller launch string for gstreamer library.
 *
 * @param 'launchstart' is the beginning of the launch string
 * @param 'launchsettings' are the settings for launching the gstreamer RTSP server
 * @param 'rootstreampath' is copied from scr_array
 * @param 'rootlaunchstring' is copied from 'rootlaunchstring'.
 *         This string launches the gstreamer RTSP server from the gstreamer library
 */
void rootstream::getrootlaunchstring() {
    gchar *launchsstart = "( rtspsrc location=";
    gchar *launchsettings = " latency=0 ! rtph264depay ! h264parse ! rtph264pay name=pay0 pt=96 )";

    int srclength = this->rootstreampath.length();
    gchar src_array[srclength + 1];
    strcpy(src_array, this->rootstreampath.c_str());

    this->rootlaunchstring += launchsstart;
    this->rootlaunchstring += src_array;
    this->rootlaunchstring += launchsettings;
    this->rootrtspsrc = rootlaunchstring.c_str();
}

/**
 * Rootstream creates the controller server with help of gstreamer library.
 *
 * @param call to get the launch string for the server
 * @param create the RTSP server with help of gstreamer library
 */
void rootstream::createrootstream() {
    //this->rootrtspsrc = "( rtspsrc location=rtsp://192.168.0.62:554:554/MediaInput/h264/stream_1 ! rtph264depay ! h264parse ! rtph264pay name=pay0 pt=96 )";
    this->getrootlaunchstring();
    this->createrootRTSPserver();
}

/**
 * Rootstream creates the controller RTSP server with help of gstreamer library.
 *
 * Unused functions from gstreamer library commented out.
 *
 * @param 'rootserver' instantiates an new gstreamer rtsp media factory object
 * @param 'rootmounts' gets the rtsp media factory mount points
 * @param generate the launch string for root rtsp server
 * @param 'gst_rtsp_mount_points_add_factory' add a new factory from the gstreamer library
 * @param 'rootmounts' which is defined before
 * @param 'rootstreamurl' which is defined before
 * @param the created 'rootfactory'
 * @param start 'g_main_loop_new' in 'rootloop'
 * @param attache 'rootserver' to 'gst_rtsp_server_attach'
 * @param set the 'rootcreateRTSPserverstatus' to 'true' after all build up
 */
void rootstream::createrootRTSPserver() {
    this->rootserver = gst_rtsp_server_new ();

    // this->rootfactory = rootfactory = gst_rtsp_media_factory_new ();
    //gst_rtsp_media_factory_set_launch (this->rootfactory, this->rootrtspsrc);

    //gst_rtsp_media_factory_set_shared (this->rootfactory, TRUE);

    /* get the default mount points from the rootserver */
    this->rootmounts = gst_rtsp_server_get_mount_points (this->rootserver);

    // Generate rootstream rootserver url
    const gchar *slash = "/";
    std::string url = slash + this->camip;
    const gchar *rootstreamurl = url.c_str();

    /* attach the video test signal to the "/test" URL */
    gst_rtsp_mount_points_add_factory (this->rootmounts, rootstreamurl , this->rootfactory);
    g_object_unref (this->rootmounts);

    /* make a mainloop for the default context */
    this->rootloop = g_main_loop_new (NULL, FALSE);

    /* attach the rootserver to the default maincontext */
    gst_rtsp_server_attach (this->rootserver, NULL);

    this->rootcreateRTSPserverstatus = true;
}

/**
 * Rootstream creates the root main loop from the gstreamer library.
 *
 * @param wait till everything build up -> threading problem
 * @param create 'g_main_loop_run' with 'rootloop'
 */
void rootstream::startrootstreamserver() {
    // Threading problem
    while (!this->rootcreateRTSPserverstatus) {}
    /* start serving gst-rtsp-rootserver */
    std::cout << "--STREAM READY--\nCamera (" + this->camip + ") -> Connection was successful." << std::endl;
    g_main_loop_run (this->rootloop);
}

/**
 * Rootstream check if main loop from gstreamer library is still running
 *
 * @return 'true' if the main loop from 'rootloop' is still running
 */
bool rootstream::check_g_main_loop_is_running() {
    return g_main_loop_is_running(this->rootloop);
}

/**
 * - Deprecated -
 *
 * void rootstream::initstream() {
    //this->capture = cv::VideoCapture(this->rootstreampath);
    //this->capture = cv::VideoCapture(0);

    if (!capture.isOpened()) {
        std::cout << "Error opening video stream." << std::endl;
        this->reconnectstream();
    } else {
        std::cout << "Cameracontroller: (" + this->camip + ") -> Connected to Rootstream. Start reading root frames." << std::endl;
        this->readrootframe();
    }
}

void rootstream::reconnectstream() {
    while (1) {
        this->capture.release();
        this->capture = cv::VideoCapture(this->rootstreampath);
        std::cout << "Try to reconnect Rootstream." << std::endl;

        if (capture.isOpened()){
            std::cout << "Reconnect video stream succsessful.\n" << std::endl;
            return;
        }
    }
}

cv::Mat rootstream::readrootframe() {
    cv::Mat frame;
    this->capture >> frame;

    return frame;
}
 */
