/**
@file LEDHandler.cpp
*/

#include "LEDHandler.h"

LEDHandler::LEDHandler():Handler(),status(false) {}

void LEDHandler::get(httplib::Server *ws) {
    ws->Get("/led/status", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(std::to_string(status), "text/plain");
    });
}

void LEDHandler::post(httplib::Server *ws) {
    ws->Post("/led/status", [this](const httplib::Request& req, httplib::Response& res) {

    });
}

void LEDHandler::setStatus(bool s) {
    status = s;
}

bool LEDHandler::getStatus() const {
    return status;
}