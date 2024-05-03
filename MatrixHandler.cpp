/**
@file MatrixHandler.cpp
*/

#include "MatrixHandler.h"

MatrixHandler::MatrixHandler():Handler(),msg("") {}

void MatrixHandler::get(httplib::Server *ws) {
    ws->Get("/matrix/data", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(msg, "text/plain");
    });
}

void MatrixHandler::post(httplib::Server *ws) {
    ws->Post("/matrix/data", [](const httplib::Request& req, httplib::Response& res) {
    });
}

void MatrixHandler::setMessage(std::string m) {
    msg = m;
}

std::string MatrixHandler::getMessage() const {
    return msg;
}
