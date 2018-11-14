#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "plansza.h"
#include "kratka.h"
#include "logic.h"
#include "ustawienia.h"

class Game
{
public:
    Game();
    ~Game();

    void startGame();
private:

    void redraw();
    void updateSterowanie();
    void updateGame();
    void zmienParamOkna();

    sf::RenderWindow window;

    sf::Clock clockRedraw;
    sf::Clock clockSterowanie;
    sf::Clock clockLogic;

    float frametime;
    float stertime;
    float logictime;

    Plansza *p;
    Kratka *k;
    Logic *l;
    Ustawienia *u;

    sf::Vector2i vtmp;

    bool flagatest;
    bool flagaLewyMysz;
    int licznik;


};

#endif // GAME_H
