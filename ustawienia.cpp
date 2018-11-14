#include "ustawienia.h"
#include "wspolne.h"

Ustawienia::Ustawienia()
{

}

void Ustawienia::saveSettings(sf::RenderWindow &window)
{
    QSettings settings("PeterWhite","kratki");
    settings.beginGroup("ParametryCwiczenia");
    settings.setValue("iloscwybranych",iloscwybranych);
    settings.setValue("grubosclini",grubosclini);
    settings.setValue("screenwidth",screenwidth);
    settings.setValue("screenheight",screenheight);
    settings.setValue("iloscrzedow",iloscrzedow);
    settings.setValue("ilosckolumn",ilosckolumn);
    int x = window.getPosition().x;
    int y = window.getPosition().y;
    settings.setValue("getPositionX",x);
    settings.setValue("getPositionY",y);
    settings.endGroup();
}

void Ustawienia::loadSettings(sf::RenderWindow &window)
{
    QSettings settings("PeterWhite","kratki");
    settings.beginGroup("ParametryCwiczenia");
    iloscwybranych = settings.value("iloscwybranych",10).toInt();
    grubosclini = settings.value("grubosclini",1).toInt();
    screenwidth = settings.value("screenwidth",800).toInt();
    screenheight = settings.value("screenheight",600).toInt();
    iloscrzedow = settings.value("iloscrzedow",7).toInt();
    ilosckolumn = settings.value("ilosckolumn",6).toInt();
    int x = settings.value("getPositionX",0).toInt();
    int y = settings.value("getPositionY",0).toInt();
    window.setPosition(sf::Vector2i(x,y));

    wysokosckratki = screenheight/iloscrzedow;
    szerokosckratki = screenwidth/ilosckolumn;

    settings.endGroup();
}

