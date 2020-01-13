#include "environnement.h"

///constructeur qui va servir pour les classes filles
Environnement::Environnement(Coords coords)
    : m_coords{coords} {}

///Accesseur Retourne un type Coords ex: {0,0} dans l'ordre l'abcisse et l'ordonnée
Coords Environnement::getCoords() const {
    return m_coords;
}

///Mutateur Coords
void Environnement::setCoords(Coords coords) {
    m_coords = coords;
}
