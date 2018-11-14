#include "logic.h"
#include "wspolne.h"
vector<sf::Vector2i >::iterator Logic::itvWszystPozycje;
vector<sf::Vector2i >::iterator Logic::itvWybrane;

Logic::Logic()
{
    wypelnijWektorvWszystPozycje();
    pomieszajWektorvWszystPozycje();
    wypelnijWektorvWybrane();
    itvWybrane = vWybrane.begin();
}


void Logic::wypelnijWektorvWszystPozycje()
{
    vWszystPozycje.clear();
    for( int j=0; j < iloscrzedow; j++)
        for(int i=0; i < ilosckolumn; i++) {
            vWszystPozycje.push_back(sf::Vector2i(i,j));
        }
    itvWszystPozycje = vWszystPozycje.begin();
}

void Logic::wypelnijWektorvWybrane()
{
    for(int i=0; i< iloscwybranych; ++i) {
        vWybrane.push_back(vWszystPozycje.at(i));
    }
}
void Logic::pomieszajWektorvWszystPozycje()
{
    std::random_shuffle ( vWszystPozycje.begin(), vWszystPozycje.end() );
    itvWszystPozycje = vWszystPozycje.begin();
}
void Logic::testWyswietlWektor()
{
    int licznik =0;
    sf::Vector2i wartosci;
    for( int j=0; j < iloscrzedow; ++j)
        for(int i=0; i < ilosckolumn; ++i) {
            wartosci = vWszystPozycje.at(licznik);
            ++licznik;
        }
}

sf::Vector2i Logic::getPozycje()
{
    return (*(itvWybrane++));

}

sf::Vector2i Logic::getWybrane()
{
    if(itvWybrane != vWybrane.end()) {
        return (*(itvWybrane++));
    }
    else {

        return sf::Vector2i(-1,-1);
    }
}

std::vector<sf::Vector2i> Logic::getWektorWybrane()
{
    return vWybrane;
}
sf::Vector2i  Logic::checkPole(const sf::Vector2i &poz)
{
    sf::Vector2i vtmp(-1,-1);
    for( unsigned int i=0; i < vWybrane.size(); ++i) {
        if( poz.x >  (vWybrane.at(i).x * szerokosckratki) && poz.x <  (vWybrane.at(i).x * szerokosckratki + szerokosckratki)
                &&  poz.y >  (vWybrane.at(i).y * wysokosckratki)  && poz.y <  (vWybrane.at(i).y * wysokosckratki +  wysokosckratki) )
        {
            vtmp = vWybrane.at(i);

        }
    }
    return vtmp;
}

void Logic::stanPoczatkowy()
{
    vWybrane.clear();

    wypelnijWektorvWszystPozycje();
    pomieszajWektorvWszystPozycje();
    wypelnijWektorvWybrane();
    itvWybrane = vWybrane.begin();
}
