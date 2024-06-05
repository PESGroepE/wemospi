/**
@file RFIDHandler.cpp
*/

#include "RFIDHandler.h"

RFIDHandler::RFIDHandler(std::string v, MatrixHandler *m, Deuren *d):Handler(),valid(v),matrix(m),deuren(d) {
}

void RFIDHandler::get(httplib::Server *ws) {
    ws->Get("/rfid/status", [](const httplib::Request& req, httplib::Response& res) {

    });
}

void RFIDHandler::post(httplib::Server *ws) {
    ws->Post("/rfid/tag", [this](const httplib::Request& req, httplib::Response& res) {
        std::cout << "rfid tag post inbound" << std::endl;
        if (req.has_param("data")) {
            std::string tag = req.get_param_value("data");
            if (tag=="f9596c15") {
                matrix->setMessage("jon");
            } else if (tag=="") {
                matrix->setMessage("alisa");
            } else {
                matrix->setMessage(tag);
            }
            matrix->setMessage(tag);
            deuren->openSluis(Sluisopties::BUITEN);
            std::cout << tag << std::endl;
        } else {
            res.status = 400;
        }
    });
}
