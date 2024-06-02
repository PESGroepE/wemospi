#ifndef WEMOSPI_EVENT_H
#define WEMOSPI_EVENT_H

#include <string>

/**
 * @brief Enum met event types.
 */
enum Type {
    NONE,
    HUMIDITY,
    BRAND,
    SLUISKNOP,
    NOODKNOP,
    TEMP
};

/**
 * @brief Event klasse die gebruikt wordt om socket/bus berichten door te geven.
 */
class Event {
public:
    /**
    * Construeer een nieuw Event object.
    * @brief Constructor.
    */
    Event();

    /**
    * Construeer een nieuw Event object.
    * @brief Constructor.
    * @param type Type van het event.
    * @param data String met de data van het event.
    */
    Event(Type, std::string);

    /**
    * @brief Haal het type van het event op.
    */
    Type getType() const;

    /**
    * @brief Haal de data van het event op.
    */
    std::string getData() const;

    /**
    * @brief Stel het type van het event in.
    * @param type Type van het event, afkomstig uit de type enum.
    */
    void setType(Type);

    /**
    * @brief Stel de data van het event in.
    * @param data String met de data van het event.
    */
    void setData(std::string);

private:
    /**
    * Type van het event, afkomstig uit de type enum.
    */
    Type type;

    /**
    * String met de data van het event.
    */
    std::string data;
};

#endif //WEMOSPI_EVENT_H
