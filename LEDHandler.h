#ifndef WEMOSPI_LEDHANDLER_H
#define WEMOSPI_LEDHANDLER_H

#include "Handler.h"

/**
 * @brief LEDHandler klasse die gebruikt wordt om de leds aan te sturen.
 */
class LEDHandler: public Handler {
public:
    /**
    * Construeer een nieuw LEDHandler object.
    * @brief Constructor.
    */
    LEDHandler();

    /**
    * @brief Roep een get handler aan.
    * @param svr Pointer naar de httpserver.
    */
    void get(httplib::Server*);

    /**
    * @brief Roep een post handler aan.
    * @param svr Pointer naar de httpserver.
    */
    void post(httplib::Server*);

    /**
    * @brief Stel de status van de leds in.
    * @param status Boolean die de status van de leds bepaalt.
    */
    void setStatus(bool);

    /**
    * @brief Haal de status van de leds op.
    */
    bool getStatus() const;

    void setKleur(std::string);

    std::string getKleur() const;

    void setBrand(bool);

    bool getBrand() const;

private:
    /**
    * Status van de leds.
    */
    bool status;

    std::string kleur;

    bool brand;
};


#endif //WEMOSPI_LEDHANDLER_H
