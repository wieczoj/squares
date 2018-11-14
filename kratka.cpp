#include "kratka.h"
#include "wspolne.h"

Kratka::Kratka()
{

}
void Kratka::pokazKratka(sf::RenderWindow &window, sf::Vector2i pozycja)
{
    kwadrat.setFillColor(sf::Color::Green);
    kwadrat.setPosition(sf::Vector2f(pozycja.x * szerokosckratki, pozycja.y * wysokosckratki));
    kwadrat.setSize(sf::Vector2f(szerokosckratki,wysokosckratki));
    window.draw(kwadrat);
}

void Kratka::ukryjKratke(sf::RenderWindow &window, sf::Vector2i pozycja)
{

}
