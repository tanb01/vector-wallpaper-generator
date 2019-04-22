#ifndef HEURE_H_INCLUDED
#define HEURE_H_INCLUDED

#include <iostream>
#include "util/util.h"

class Heure
{
    ///Méthodes : Déclaration
public:
    Heure();
    Heure(std::mt19937& rg);
    ~Heure();
    void saisirHeure();
    unsigned int getHeure();
    unsigned int getMinutes();
    bool Nuit_ou_Jour();

    ///Attributs : Déclaration
private:
    unsigned int m_heure;
    unsigned int m_minute;
};

#endif // HEURE_H_INCLUDED
