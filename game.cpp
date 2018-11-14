#include "game.h"
#include "wspolne.h"
#include "ustawienia.h"

void (Kratka::*pFunc)(sf::RenderWindow &window, sf::Vector2i pozycja);

Game::Game()
    :window(sf::VideoMode(screenwidth, screenheight), "Squares!",4),flagatest(false),flagaLewyMysz(false)
{

    Ustawienia u;
    u.loadSettings(window);

    licznik = 0;
    window.setFramerateLimit(60); // 60 FPS cap.
    frametime = 1.0f / 60.0f;
    stertime = 0.1f;
    logictime = 0.6f;

    p = new Plansza;
    k = new Kratka;
    l = new Logic;


    pFunc = &Kratka::ukryjKratke;
    window.setTitle(to_string(iloscwybranych) + string("  ") + to_string(iloscrzedow) + string("x") + to_string(ilosckolumn));

}

Game::~Game()
{
    delete p;
    delete k;
    delete l;

}

void Game::startGame()
{
    while (window.isOpen())
    {

        if(clockRedraw.getElapsedTime().asSeconds() >= frametime) {
            clockRedraw.restart();
            redraw();
        }

        if(clockSterowanie.getElapsedTime().asSeconds() >= stertime) {
            clockSterowanie.restart();
            updateSterowanie();
        }

        if(clockLogic.getElapsedTime().asSeconds() >= logictime) {
            clockLogic.restart();
            if(licznik < iloscwybranych*2) {
                updateGame();
                ++licznik;
            }
        }

    }
}
void Game::redraw()
{
    if(licznik == iloscwybranych*2 && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        std::vector<sf::Vector2i> Wybrane(l->getWektorWybrane());
        p->rysujWyniki(window, Wybrane );
    } else if(licznik == iloscwybranych*2 && flagaLewyMysz == true) {
        (k->*pFunc)(window,vtmp);
    } else if(licznik <= iloscwybranych*2) {
        window.clear();

        (k->*pFunc)(window,vtmp);
    }
    p->rysujPlansze(window);
    window.display();
}
void Game::updateGame()
{
    flagatest?flagatest=false:flagatest=true;
    if(flagatest) {
        vtmp = l->getPozycje();
        pFunc = &Kratka::pokazKratka;
    } else {
        pFunc = &Kratka::ukryjKratke;
    }
}
void Game::updateSterowanie()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                vtmp = l->checkPole(sf::Vector2i(event.mouseButton.x,event.mouseButton.y));
                if(vtmp.x != -1) {
                    pFunc = &Kratka::pokazKratka;
                    flagaLewyMysz = true;
                }
            }
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {

                pFunc = &Kratka::ukryjKratke;
                licznik = 0;
                flagaLewyMysz = false;
                flagatest = false;
                l->stanPoczatkowy();
                clockLogic.restart();

            } else if(event.key.code == sf::Keyboard::PageUp) {

                if(iloscwybranych < ilosckolumn*iloscrzedow) {
                    ++(iloscwybranych);

                }
            } else if(event.key.code == sf::Keyboard::PageDown) {

                if(iloscwybranych > 2) {
                    --(iloscwybranych);

                }
            }

            else if(event.key.code == sf::Keyboard::Up) {
                ++iloscrzedow;
                zmienParamOkna();
            } else if(event.key.code == sf::Keyboard::Right) {
                ++ilosckolumn;
                zmienParamOkna();
            } else if(event.key.code == sf::Keyboard::Left) {
                if(ilosckolumn * iloscrzedow > iloscwybranych && ilosckolumn > 1) {
                    --ilosckolumn;
                    zmienParamOkna();
                }
            } else if(event.key.code == sf::Keyboard::Down) {
                if(ilosckolumn * iloscrzedow > iloscwybranych && iloscrzedow > 1) {
                    --iloscrzedow;
                    zmienParamOkna();
                }
            } else if(event.key.code == sf::Keyboard::S) {
                u = new Ustawienia;
                u->saveSettings(window);
                delete u;
            }


            window.setTitle(to_string(iloscwybranych) + string("  ") + to_string(iloscrzedow) + string("x") + to_string(ilosckolumn));
        }
        if (event.type == sf::Event::Resized) {
            screenwidth = window.getSize().x;
            screenheight = window.getSize().y;
            zmienParamOkna();
        }
    }
}

void Game::zmienParamOkna()
{
    wysokosckratki = screenheight/iloscrzedow;
    szerokosckratki = screenwidth/ilosckolumn;
    window.clear();
    p->rysujPlansze(window);
    window.display();
}

