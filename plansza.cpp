#include "plansza.h"
#include "wspolne.h"
#include <iostream>

Plansza::Plansza()
{
}
void Plansza::rysujPlansze(sf::RenderWindow &window)
{
    line.setSize(sf::Vector2f(screenwidth, grubosclini));

    for(int i=0; i< iloscrzedow; ++i) {
        line.setPosition(sf::Vector2f(0,  i * wysokosckratki));
        window.draw(line);
    }

    line.setSize(sf::Vector2f(grubosclini,screenwidth));

    for(int j=0; j < ilosckolumn; ++j) {

        line.setPosition(sf::Vector2f(j * szerokosckratki,  0));
        window.draw(line);
    }
}
void Plansza::rysujWyniki(sf::RenderWindow &window, std::vector<sf::Vector2i> &vWybrane)
{
    for( unsigned int i=0; i < vWybrane.size(); ++i) {
        kwadrat.setFillColor(sf::Color::Green);
        kwadrat.setPosition(sf::Vector2f(vWybrane.at(i).x * szerokosckratki, vWybrane.at(i).y * wysokosckratki));
        kwadrat.setSize(sf::Vector2f(szerokosckratki,wysokosckratki));
        window.draw(kwadrat);
    }
}
