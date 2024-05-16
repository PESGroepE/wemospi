//
// Created by lucasridder on 5/16/24.
//

#ifndef WEMOSPI_EVENT_H
#define WEMOSPI_EVENT_H

#include <string>

enum Type {
    NONE,
    HUMIDITY
};

class Event {
public:
    Event();
    Event(Type, std::string);
    Type getType() const;
    std::string getData() const;
    void setType(Type);
    void setData(std::string);

private:
    Type type;
    std::string data;
};

#endif //WEMOSPI_EVENT_H
