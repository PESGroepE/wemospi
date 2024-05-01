#include "MotionHandler.h"

MotionHandler::MotionHandler(LEDHandler* l):Handler(),led(l) {}

void MotionHandler::get(httplib::Server *ws) {
    ws->Get("/motion/status", [](const httplib::Request& req, httplib::Response& res) {

    });
}

void MotionHandler::post(httplib::Server *ws) {
    ws->Post("/motion/status", [this](const httplib::Request& req, httplib::Response& res) {
        std::cout << "motion sensor post inbound" << std::endl;
        if (req.has_param("value")) {
            std::string data = req.get_param_value("value");
            std::cout << data << std::endl;
            if (data=="true") {
                led->setStatus(true);
            } else {
                led->setStatus(false);
            }

        } else {
            res.status = 400;
        }
    });
}