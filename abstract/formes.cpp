#include "formes.h"

///constructeur utilisé directement par  Ellipse, Cercle, Triangle, Rectangle
///attention forme non instanciable seulement par le biais de ses classes filles
Formes::Formes(Coords coords, Couleur couleur)
    : m_coords{coords}, m_couleur{couleur} {}

///Accesseur Retourne un type Couleur ex: {0,0,0} dans l'orde la composante Rouge, Vert , Bleu
Couleur Formes::getCouleur() const {
    return m_couleur;
}

///Accesseur Retourne un type Coords ex: {0,0} dans l'ordre l'abcisse et l'ordonnée
Coords Formes::getCoords() const {
    return m_coords;
}

///Mutateur Coords
void Formes::setCoords(Coords coords) {
    m_coords = coords;
}

///Mutateur Couleur
void Formes::setCouleur(Couleur couleur) {
    m_couleur = couleur;
}

///Translation selon un coefficient
void Formes::Translater(double coeff) {
    this->setCoords(coeff * m_coords);
}

///Translation en abcisse selon une constante
void Formes::TranslaterX(double consta) {
    this->setCoords({consta + (this->getCoords().getX()), this->getCoords().getY()});
}

///Translation en aordonnée selon une constante
void Formes::TranslaterY(double consta) {
    this->setCoords({this->getCoords().getX(), consta + (this->getCoords().getY())});
}

