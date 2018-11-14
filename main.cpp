#include <SFML/Graphics.hpp>
#include <string>
#include "game.h"

int grubosclini = 1;
int iloscwybranych = 10;
int screenwidth = 800;
int screenheight = 600;
int iloscrzedow = 7;
int ilosckolumn = 6;
int wysokosckratki = screenheight/iloscrzedow;
int szerokosckratki = screenwidth/ilosckolumn;


int main()
{
    std:: srand(static_cast<unsigned int>(time(nullptr)));
    Game g;
    g.startGame();
    return 0;
}
