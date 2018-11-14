#ifndef LOGIC_H
#define LOGIC_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;
class Logic
{
public:
    Logic();


    sf::Vector2i getPozycje();
    sf::Vector2i getWybrane();
    std::vector< sf::Vector2i > getWektorWybrane();
    sf::Vector2i checkPole(const sf::Vector2i &poz);
    void stanPoczatkowy();
    void testWyswietlWektor();

private:
    vector<sf::Vector2i> vWszystPozycje;
    vector<sf::Vector2i> vWybrane;
    static   vector<sf::Vector2i>::iterator itvWszystPozycje;
    static   vector<sf::Vector2i>::iterator itvWybrane;
    void wypelnijWektorvWszystPozycje();
    void wypelnijWektorvWybrane();
    void pomieszajWektorvWszystPozycje();


};

#endif // LOGIC_H
