//
// Created by Phillip Mai on 18.03.20.
//

#include "cameracontroller.h"

/**
 * Cameracontroller class.
 *
 * Simulates a controller for a camera.
 * Each controller controls and simulates a camera defined in the XML.
 * The client device doesn't communicate directly with the camera,
 * it communicates with this camera class,
 * which opens sockets with which the client device can communicate.
 */
cameracontroller::cameracontroller() {}; // Default constructor

/**
 * Cameracontroller constructor.
 *
 * @param 'thisCamera' is the camera who will be controlled
 * @param 'rootstreampath' is the RTSP URL to the camera that is being controlled/connected
 *
 * Create the server for the controller with 'createcontrollerserver' before the clientserver starts.
 */
cameracontroller::cameracontroller(Camera camera) {
    this->thisCamera = camera;
    this->rootstreampath = this->getrootstreampath();
    this->createcontrollerserver();
}

/**
 * Cameracontroller creates and retrieves the rootstream path.
 *
 * @param 'thisCamera.protocol' distinguishes between RTSP and NDI
 * @return URL to communicate with camera
 *
 * NDI not implemented yet.
 */
std::string cameracontroller::getrootstreampath() {
    if (this->thisCamera.protocol.compare("rtsp") == 0) {
        return this->thisCamera.protocol + "://" + this->thisCamera.camip + ":554/MediaInput/" + "h264" + "/stream_1";
    } else if (this->thisCamera.protocol.compare("ndi") == 0) {
        return "NDI URL";
    } else {
        std::cout << " --ERROR--\nCamera (" + this->thisCamera.camip + ") -> Connection could not be established.\n" << std::endl;
        return "";
    }
}

/**
 * Cameracontroller creates and retrieves
 * the controller launch string for gstreamer library.
 *
 * @param 'launchstart' is the beginning of the launch string
 * @param 'launchsettings' are the settings for launching the gstreamer RTSP server
 * @param 'rootstreampath' is copied from scr_array
 * @param 'controllersrc' is copied from 'controllerlaunchstring'.
 *         This string launches the gstreamer RTSP server from the gstreamer library
 */
void cameracontroller::getcontrollerlaunchstring() {
    gchar *launchsstart = "( rtspsrc location=";
    gchar *launchsettings = " latency=0 ! rtph264depay ! h264parse ! rtph264pay name=pay0 pt=96 )";

    int srclength = this->rootstreampath.length();
    gchar src_array[srclength + 1];
    strcpy(src_array, this->rootstreampath.c_str());

    this->controllerlaunchstring += launchsstart;
    this->controllerlaunchstring += src_array;
    this->controllerlaunchstring+= launchsettings;
    this->controllersrc = controllerlaunchstring.c_str();
}

/**
 * Cameracontroller creates the controller server with help of gstreamer library.
 *
 * @param call to get the launch string for the server
 * @param create the RTSP server with help of gstreamer library
 */
void cameracontroller::createcontrollerserver() {
    this->getcontrollerlaunchstring();
    this->createcontrollerRTSPserver();
}

/**
 * Cameracontroller creates the controller RTSP server with help of gstreamer library.
 *
 * @param 'controllerfactory' instantiates an new gstreamer rtsp media factory object
 * @param 'gst_rtsp_media_factory_set_launch' launches the rtsp media factory
 * @param 'controllerfactory' is the mew instantiated object
 * @param 'controllersrc' is the launch string
 * @param 'gst_rtsp_media_factory_set_shared' sets the options to multiple clients
 */
void cameracontroller::createcontrollerRTSPserver() {
    this->controllerfactory = gst_rtsp_media_factory_new();

    gst_rtsp_media_factory_set_launch (this->controllerfactory, this->controllersrc);
    gst_rtsp_media_factory_set_shared (this->controllerfactory, TRUE);
}

/**
 * Cameracontroller initialices all streams to clients defined in XML.
 *
 * OpenCV functions commented out.
 * Initialize all clientstreams defined in XML.
 * Add instanced thread object from client stream array to thread array.
 *
 * @param wait till all streams initialized, then set 'initclientstreamsStatus' to 'true'
 * @param start all client streams with 'startclientstreams'
 */
void cameracontroller::initclientstreams() {
    if (!this->rootstreampath.compare("") == 0) {
        //this->thisRootstream = rootstream(this->rootstreampath, this->thisCamera.camip, this->controllerfactory);
        //rootstream *rootstreamThread = &this->thisRootstream;
        //this->startrootRTSPserverThread = std::thread(&rootstream::startrootstreamserver, rootstreamThread);

        //bool check = this->thisRootstream.check_g_main_loop_is_running();
        //while (check == 0) {check = this->thisRootstream.check_g_main_loop_is_running();}

        //std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        //std::cout << "Cameracontroller: (" + this->thisCamera.camip + ") -> Start init all clientstreams." << std::endl;

        for (int i = 0; i < this->thisCamera.streamcounter; ++i) {
            this->thisClientstreams[i] = clientstream(this->thisCamera.clientstreams[i], this->rootstreampath, this->thisCamera.serverip, this->controllerfactory);

            clientstream *clienstreamThread = &this->thisClientstreams[i];
            this->startstreamserverThread[i] = std::thread(&clientstream::startstreamserver, clienstreamThread);

            // OpenCV threads
            //this->startsendframesThread[i] = std::thread(&clientstream::startsendframes, clienstreamThread);
        }
        this->initclientstreamsStatus = true;

        //std::cout << "Cameracontroller: (" + this->thisCamera.camip + ") -> Init all clientstreams." << std::endl;
        this->startclientstreams();
    }
}

/**
 * Cameracontroller initialices all streams to clients defined in XML.
 *
 * OpenCV functions commented out.
 * Initialize all clientstreams defined in XML.
 * Add instanced thread object from client stream array to thread array.
 *
 * @param wait till all streams initialized, then set 'initclientstreamsStatus' to 'true'
 * @param start all client streams with 'startclientstreams'
 */
void cameracontroller::startclientstreams() {
    if (!this->rootstreampath.compare("") == 0) {
        //std::cout << "Cameracontroller: (" + this->thisCamera.camip + ") -> Start all clientstreams." << std::endl;
        for (int i = 0; i < this->thisCamera.streamcounter; i++) {
            if (i < 1) {
                //std::cout << "Camera (" + this->thisCamera.camip + ") -> rtsp://localhost:8554/" + this->thisCamera.camip << std::endl;
                //this->startrootRTSPserverThread.join();
            }
            this->startstreamserverThread[i].join();

            // OpenCV threads
            //this->startsendframesThread[i].join();
        }
    }
}

// Rootstream via OpenCV
/**
 * Cameracontroller retrieves root frame from OpenCV rtsp socket API.
 *
 * OpenCV functions commented out.
 * This function not in use right now.
 *
 * @param 'rootframe' is the frame from the camera. -> The 'rootframe' only exist once (Singleton)
 */
void cameracontroller::getrootframe() {
    std::cout << "Cameracontroller: (" + this->thisCamera.camip + ") -> getrootframe()." << std::endl;
    while (1) {
        //this->rootframe = this->thisRootstream.readrootframe();
    }
}

/**
 * Cameracontroller sends root frame from OpenCV rtsp socket API.
 *
 * OpenCV functions commented out.
 * This function not in use right now.
 *
 * @param initialize all client streams and wait till all finished -> threading problem
 * @param check streaming protocol from url
 *
 * @param 'rtsp' start send rootframe to client streams. -> The 'rootframe' only exist once (Singleton)
 * @param 'ndi' not implemented
 */
void cameracontroller::sendrootframe() {
    // Waiting till all streams init. -> Threading problem.
    while (!this->initclientstreamsStatus) {
        std::cout << "\nCameracontroller: (" + this->thisCamera.camip + ") -> Init clientstreams not ready...\n" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    std::cout << "Cameracontroller: (" + this->thisCamera.camip + ") -> All cientstreams ready." << std::endl;
    std::cout << "Cameracontroller: (" + this->thisCamera.camip + ") -> sendrootframe()." << std::endl;
    for (int i = 0; i < this->thisCamera.streamcounter; i++) {
        std::string streamprotocol = this->thisClientstreams[i].getclientstreamprotocol();

        if (streamprotocol.compare("rtsp") == 0) {

            while (1) {
                //this->thisClientstreams[i].setrootframe(this->rootframe);
            }

        } else if (streamprotocol.compare("ndi") == 0) {

        }
    }
}
