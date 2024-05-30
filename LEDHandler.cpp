/**
@file LEDHandler.cpp
*/

#include "LEDHandler.h"

LEDHandler::LEDHandler():Handler(),status(false) {}

void LEDHandler::get(httplib::Server *ws) {
    ws->Get("/led/status", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(std::to_string(getStatus()), "text/plain");
    });

    ws->Get("/led/color", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(getKleur(), "text/plain");
    });

    ws->Get("/led/brand", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(std::to_string(getBrand()), "text/plain");
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

void LEDHandler::setKleur(std::string k) {
    kleur = k;
}

std::string LEDHandler::getKleur() const {
    return kleur;
}

void LEDHandler::setBrand(bool b) {
    brand = b;
}

bool LEDHandler::getBrand() const {
    return brand;
}
