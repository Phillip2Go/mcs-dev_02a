//
// Created by Phillip Mai on 22.03.20.
//

#include <iostream>
#include "clientstream.h"

/**
 * Clientstream class.
 *
 * Creates a stream, that a client device can receive.
 * Reads the root frame from the camera, converts it
 * and sends it to the client device.
 *
 */
clientstream::clientstream() {}; // Default constructor

/**
 * Clientstream class starts with constructor.
 *
 * @param get 'thisClientstream' from constructor
 * @param get 'rootstreampath' from constructor
 * @param get 'serverip' from constructor
 * @param get GstRTSPMediaFactory 'factory' from constructor
 * @def create client stream with given settings
 */
clientstream::clientstream(Stream clientstream, std::string rootstreampath, std::string serverip, GstRTSPMediaFactory  *controllerfactory) {
    this->thisClientstream = clientstream;
    this->rootstreampath = rootstreampath;
    this->serverip = serverip;
    this->factory = controllerfactory;
    this->createstream();
}

/**
 * Clientstream creates and retrieves
 * the controller launch string for gstreamer library.
 *
 * @param 'launchstart' is the beginning of the launch string
 * @param 'launchsettings' are the settings for launching the gstreamer RTSP server
 * @param 'rootstreampath' is copied from scr_array
 * @param 'rootlaunchstring' is copied from 'rootlaunchstring'.
 *         This string launches the gstreamer RTSP server from the gstreamer library
 */
void clientstream::getlaunchstring() {
    gchar *launchsstart = "( rtspsrc location=";
    gchar *launchsettings = " latency=0 ! rtph264depay ! h264parse ! rtph264pay name=pay1 pt=98 )";

    int srclength = this->rootstreampath.length();
    gchar src_array[srclength + 1];
    strcpy(src_array, this->rootstreampath.c_str());

    this->launchstring += launchsstart;
    this->launchstring += src_array;
    this->launchstring += launchsettings;
    this->rtspsrc = launchstring.c_str();
}

/**
 * Clientstream creates the client server with help of gstreamer library.
 *
 * @def call to get the launch string for the server
 * @def create the RTSP server with help of gstreamer library
 * @if NDI not implemented yet
 */
void clientstream::createstream() {
    if (this->thisClientstream.streamprotocol.compare("rtsp") == 0) {
        //this->rtspsrc = "( rtspsrc location=rtsp://localhost:8554/192.168.0.62 ! rtph264depay ! h264parse ! rtph264pay name=pay1 pt=97 )";
        this->getlaunchstring();
        this->createRTSPserver();

    } else if (this->thisClientstream.streamprotocol.compare("ndi") == 0) {
        this->ndisrc = rootstreampath;
    }
}

/**
 * Clientstream creates the client RTSP server with help of gstreamer library.
 *
 * Unused functions from gstreamer library commented out.
 *
 * @param create a new gstreamer rtsp server in 'server'
 * @def set server address with 'gst_rtsp_server_set_address'
 * @def set server port with 'gst_rtsp_server_set_service'
 * @param store server mount points in 'mounts'
 * @def add this 'factory' to gstreamer mount points with 'gst_rtsp_mount_points_add_factory'
 * @def create main loop from gstreamer
 * @def attache 'server' to 'gst_rtsp_server_attach'
 * @param set the 'createRTSPserverstatus' to 'true' after all build up
 */
void clientstream::createRTSPserver() {
    this->server = gst_rtsp_server_new ();
    gst_rtsp_server_set_address(this->server, this->serverip.c_str());
    gst_rtsp_server_set_service(this->server, reinterpret_cast<const gchar *>(this->thisClientstream.port.c_str()));
    //gst_rtsp_server_set_service(this->server, "9090");

    //this->factory = factory = gst_rtsp_media_factory_new ();
    //gst_rtsp_media_factory_set_launch (this->factory, this->rtspsrc);

    //gst_rtsp_media_factory_set_shared(this->factory, TRUE);

    /* get the default mount points from the server */
    this->mounts = gst_rtsp_server_get_mount_points (this->server);

    /* attach the video test signal to the "/test" URL */
    gst_rtsp_mount_points_add_factory (this->mounts, this->thisClientstream.streamname.c_str() , this->factory);
    //gst_rtsp_mount_points_add_factory (this->mounts, "/test" , this->factory);
    g_object_unref (this->mounts);

    /* make a mainloop for the default context */
    this->loop = g_main_loop_new (NULL, FALSE);

    /* attach the server to the default maincontext */
    gst_rtsp_server_attach (this->server, NULL);

    this->createRTSPserverstatus = true;
}

/**
 * Clientstream creates the root main loop from the gstreamer library.
 *
 * @def wait till everything build up -> threading problem
 * @def create 'g_main_loop_run' with 'loop'
 * @if NDI not implemented yet
 */
void clientstream::startstreamserver() {
    if (this->thisClientstream.streamprotocol.compare("rtsp") == 0) {
        // Threading problem
        while (!this->createRTSPserverstatus) {}
        /* start serving gst-rtsp-server */
        std::cout << "Clientstream -> rtsp://" + this->serverip + ":" + this->thisClientstream.port + this->thisClientstream.streamname << std::endl;
        g_main_loop_run (this->loop);

    } else if (this->thisClientstream.streamprotocol.compare("ndi") == 0) {

    }
}

/**
 * Clientstream send frames over OpenCV API.
 *
 * Not implemented yet.
 */
void clientstream::startsendframes() {
    if (this->thisClientstream.streamprotocol.compare("rtsp") == 0) {
        
    } else if (this->thisClientstream.streamprotocol.compare("ndi") == 0) {

    }
}

/**
 * Clientstream getter, for the clientstream streaming protocol.
 *
 * @return streaming protocol: RTSP or NDI
 */
std::string clientstream::getclientstreamprotocol() {
    return this->thisClientstream.streamprotocol;
}

/**
 * - Deprecated -
 *
 * void clientstream::setrootframe(cv::Mat frame) {
    this->rootframe = frame;
}
 */
