#include "RelaxstoelHandler.h"

RelaxstoelHandler::RelaxstoelHandler() {

}

void RelaxstoelHandler::get(httplib::Server *ws) {
    ws->Get("/trilmotor/status", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(std::to_string(motor), "text/plain");
    });
}

void RelaxstoelHandler::post(httplib::Server *ws) {
    ws->Post("/druksensor/status", [this](const httplib::Request& req, httplib::Response& res) {
        if (req.body=="true") {
            motor = true;
        } else {
            motor = false;
        }
    });
}

void RelaxstoelHandler::setTrilmotor(bool s) {
    motor = s;
}

bool RelaxstoelHandler::getTrilmotor() const {
    return motor;
}
