#ifndef PLANSZA_H
#define PLANSZA_H
#include <SFML/Graphics.hpp>
#include <vector>

class Plansza
{
public:
    Plansza();
    void rysujPlansze(sf::RenderWindow &window);
    void rysujWyniki(sf::RenderWindow &window, std::vector<sf::Vector2i>& vWybrane);

private:
    sf::RectangleShape kwadrat;
    sf::RectangleShape line;

};

#endif // PLANSZA_H
