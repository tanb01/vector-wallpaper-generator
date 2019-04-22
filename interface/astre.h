#ifndef ASTRE_H_INCLUDED
#define ASTRE_H_INCLUDED

#include "../abstract/environnement.h"

///Déclaration de la classe abstraite "Astre" qui hérite de la classe
///"Environnement" et mere des classes soleil, lune, etc...
///fais hériter une couleur et des coordonnées sera utilisé dans leur fonction addCercle... pour dessiner la figure a un certain endroit
///fais aussi hériter les méthodes de translation qui sont les mêmes pour toutes les classes filles
///et a pour méthodes virtuelles pures

class Astre: public Environnement
{
    ///Methodes : déclaration
public:
    Astre(Coords coords);
};

#endif // ASTRE_H_INCLUDED
