#ifndef ASTRE_H_INCLUDED
#define ASTRE_H_INCLUDED

#include "../abstract/environnement.h"

///D�claration de la classe abstraite "Astre" qui h�rite de la classe
///"Environnement" et mere des classes soleil, lune, etc...
///fais h�riter une couleur et des coordonn�es sera utilis� dans leur fonction addCercle... pour dessiner la figure a un certain endroit
///fais aussi h�riter les m�thodes de translation qui sont les m�mes pour toutes les classes filles
///et a pour m�thodes virtuelles pures

class Astre: public Environnement
{
    ///Methodes : d�claration
public:
    Astre(Coords coords);
};

#endif // ASTRE_H_INCLUDED
