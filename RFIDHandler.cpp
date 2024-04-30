#include "RFIDHandler.h"

RFIDHandler::RFIDHandler(std::string v):Handler(),valid(v) {
}

void RFIDHandler::get(httplib::Server *ws) {
    ws->Get("/rfid/status", [](const httplib::Request& req, httplib::Response& res) {

    });
}

void RFIDHandler::post(httplib::Server *ws) {
    ws->Post("/rfid/tag", [](const httplib::Request& req, httplib::Response& res) {
        std::cout << "rfid tag post inbound" << std::endl;
        if (req.has_param("data")) {
            std::string tag = req.get_param_value("data");
            std::cout << tag << std::endl;
        } else {
            res.status = 400;
        }
    });
}
