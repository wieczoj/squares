#ifndef KRATKA_H
#define KRATKA_H

#include <SFML/Graphics.hpp>

class Kratka
{
public:
    Kratka();
    void pokazKratka(sf::RenderWindow &window, sf::Vector2i pozycja);
    void ukryjKratke(sf::RenderWindow &window, sf::Vector2i pozycja);

private:
    sf::RectangleShape kwadrat;
};

#endif // KRATKA_H
