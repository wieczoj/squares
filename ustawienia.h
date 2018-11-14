#ifndef USTAWIENIA_H
#define USTAWIENIA_H
#include <iostream>
#include <fstream>
#include <string>
#include <QSettings>
#include <SFML/Graphics.hpp>
#include <QVector2D>

class Ustawienia
{
public:
    Ustawienia();

    void saveSettings(sf::RenderWindow &window);
    void loadSettings(sf::RenderWindow &window);



private:
    std::ofstream myfile;
};

#endif // USTAWIENIA_H
