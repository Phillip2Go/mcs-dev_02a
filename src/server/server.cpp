//
// Created by Phillip Mai on 17.03.20.
//

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

#include "server.h"

using namespace tinyxml2;

/**
 * TinyXML-2 API to read and convert XML file.
 *
 * @param call to get the text as string of a element.
 *
 * @param reads 'value' from given XML file
 * @return 'value' from given XML file
 */
static std::string getElementText(tinyxml2::XMLElement *_element);
static std::string getElementText(tinyxml2::XMLElement *_element) {
    std::string value;
    if (_element != NULL) {
        value = _element->GetText();
    }

    return value;
}

/**
 * Server class.
 *
 * Server reads the XML file at start and
 * creates camera controller classes
 * with the data in the XML file.
 * The server creates a camera controller object
 * for each camera defined in the XML file.
 *
 * Server is a Singleton.
 *
 */
server::server() {}; // Default constructor

/**
 * Server class starts with constructor.
 *
 * @param load XML file with TinyXML-2 API
 * @param starts all cameras with 'initcameras'
 */
server::server(const char *xml_filename) {
    std::cout << "MCS 2.0 by Phillip Mai & Dorian Paeth.\n" << std::endl;
    std::cout << "Start server initialization." << std::endl;

    this->xml_file.LoadFile(xml_filename);
    if (xml_file.ErrorID() == 0) this->parsexmldata();

    this->initcameras();
}

/**
 * Server parse data from XML file to camera class objects.
 *
 * The TinyXML-2 parser tuns through every line
 * and takes the DEFINED (look up the XML) data
 * to create camera class object. The parser
 * uses the defined function 'getElementText'.
 *
 * @param number of cameras will be stored in 'camcounter', max number is 9 (0-9 = 10)
 * @return break if 'camcounter' > 9
 * @param camera has a 'streamcounter' who is the 'camcounter' in this function
 * @param saves the cameras in a 'cameras' array of the server class
 */
void server::parsexmldata() {
    this->camcounter = 0;
    tinyxml2::XMLElement *pRoot = this->xml_file.FirstChildElement("configXML")->FirstChildElement("camera");

    while (pRoot) {
        this->clientstreamcounter = 0;
        if (this->camcounter > 9) {
            std::cout << "Maximum number of cameras reached. break;\n" << std::endl;
            break;
        }

        Camera *thisCam = new Camera();
        if (pRoot->FirstChildElement("protocol")->GetText() != nullptr) {
            thisCam->protocol = getElementText(pRoot->FirstChildElement("protocol"));
        } if (pRoot->FirstChildElement("serverip")->GetText() != nullptr) {
            thisCam->serverip = getElementText(pRoot->FirstChildElement("serverip"));
        } if (pRoot->FirstChildElement("camip")->GetText() != nullptr) {
            thisCam->camip = getElementText(pRoot->FirstChildElement("camip"));
        } if (pRoot->FirstChildElement("authentication")->GetText() != nullptr) {
            thisCam->authentication = getElementText(pRoot->FirstChildElement("authentication"));
        } if (pRoot->FirstChildElement("width")->GetText() != nullptr) {
            thisCam->width = getElementText(pRoot->FirstChildElement("width"));
        } if (pRoot->FirstChildElement("height")->GetText() != nullptr) {
            thisCam->height = getElementText(pRoot->FirstChildElement("height"));
        } if (pRoot->FirstChildElement("camfps")->GetText() != nullptr) {
            thisCam->camfps = getElementText(pRoot->FirstChildElement("camfps"));
        } if (pRoot->FirstChildElement("at_serverip")->GetText() != nullptr) {
            thisCam->at_serverip = getElementText(pRoot->FirstChildElement("at_serverip"));
        } if (pRoot->FirstChildElement("at_camid")->GetText() != nullptr) {
            thisCam->at_camid = getElementText(pRoot->FirstChildElement("at_camid"));
        }

        tinyxml2::XMLElement *streamRoot = pRoot->FirstChildElement("streams")->FirstChildElement("stream");

        while (streamRoot) {
            if (this->clientstreamcounter > 14) {
                std::cout << "Maximum number of clientstreams reached. break;\n" << std::endl;
                break;
            }

            Stream *thisStream = new Stream();
            if (streamRoot->FirstChildElement("streamprotocol")->GetText() != nullptr) {
                thisStream->streamprotocol = getElementText(streamRoot->FirstChildElement("streamprotocol"));
            } if (streamRoot->FirstChildElement("port")->GetText() != nullptr) {
                thisStream->port = getElementText(streamRoot->FirstChildElement("port"));
            } if (streamRoot->FirstChildElement("fps")->GetText() != nullptr) {
                thisStream->fps = getElementText(streamRoot->FirstChildElement("fps"));
            } if (streamRoot->FirstChildElement("streamname")->GetText() != nullptr) {
                thisStream->streamname = getElementText(streamRoot->FirstChildElement("streamname"));
            } if (streamRoot->FirstChildElement("width")->GetText() != nullptr) {
                thisStream->width = getElementText(streamRoot->FirstChildElement("width"));
            } if (streamRoot->FirstChildElement("height")->GetText() != nullptr) {
                thisStream->height = getElementText(streamRoot->FirstChildElement("height"));
            } if (streamRoot->FirstChildElement("rectangles")->GetText() != nullptr) {
                std::string rectanglescheck = getElementText(streamRoot->FirstChildElement("rectangles"));
                if (rectanglescheck.compare("true") == 0) {
                    thisStream->rectangles = true;
                } else {
                    thisStream->rectangles = false;
                }
            }

            thisCam->clientstreams[clientstreamcounter] = *thisStream;
            this->clientstreamcounter += 1;

            streamRoot = streamRoot->NextSiblingElement("stream");
        }

        thisCam->streamcounter = this->clientstreamcounter;
        this->cameras[this->camcounter] = *thisCam;
        this->camcounter += 1;

        pRoot = pRoot->NextSiblingElement("camera");
    }

    std::cout << "Finished XML to camera parse.\n" << std::endl;
}

/**
 * Server initialize all defined cameras from XML file parse to object in camera controller array.
 *
 * @param Initialize camera with gstreamer library.
 * @param Initialize camera with OpenCV commented out.
 *
 * @param 'thisCameracontrollers' is an array that stores cameras defined in the XML file
 * @param initialize a threadable 'controllerThread' object
 * @param stores the threadable objects in a 'initclientstreamsThread' array
 * @param 'getrootframeThread' opens a Thread to get the root frames
 * @param 'sendrootframeThread' opens a Thread to send root frames
 *
 * @param Start all cameras.
 */
void server::initcameras() {
    for (int i = 0; i < this->camcounter; i++) {
        this->thisCameracontrollers[i] = cameracontroller(this->cameras[i]);

        cameracontroller *controllerThread = &this->thisCameracontrollers[i];

        // Rootstream via OpenCV
        //this->getrootframeThread[i] = std::thread(&cameracontroller::getrootframe, controllerThread);
        //this->sendrootframeThread[i] = std::thread(&cameracontroller::sendrootframe, controllerThread);

        this->initclientstreamsThread[i] = std::thread(&cameracontroller::initclientstreams, controllerThread);
    }

    this->startcameras();
}

/**
 * Server starts all defined cameras added to client stream thread array, with a join to a thread.
 *
 * @param Start camera with gstreamer library.
 * @param Start camera with OpenCV commented out.
 *
 * @param 'initclientstreamsThread' join the defined Thread object to a Thread, to start the cameras
 * @param start 'getrootframeThread' to get all the root frames over OpenCV API
 * @param send 'sendrootframeThread' to send all root frames over OpenCV API
 *
 * @param Start/Join all cameras.
 */
void server::startcameras() {
    for (int i = 0; i < this->camcounter; i++) {

        // Rootstream via OpenCV
        //this->getrootframeThread[i].join();
        //this->sendrootframeThread[i].join();

        this->initclientstreamsThread[i].join();
    }
}
