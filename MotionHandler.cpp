#include "MotionHandler.h"

MotionHandler::MotionHandler():Handler() {}

void MotionHandler::get(httplib::Server *ws) {
    ws->Get("/motion/status", [](const httplib::Request& req, httplib::Response& res) {

    });
}

void MotionHandler::post(httplib::Server *ws) {
    ws->Post("/motion/status", [](const httplib::Request& req, httplib::Response& res) {
        std::cout << "motion sensor post inbound" << std::endl;
        if (req.has_param("value")) {
            std::string tag = req.get_param_value("value");
            std::cout << tag << std::endl;
        } else {
            res.status = 400;
        }
    });
}