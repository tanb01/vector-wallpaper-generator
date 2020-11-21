#include "rectangle.h"

/// Constructeur qui prend en paramêtres quatre variables
Rectangle::Rectangle(Coords coords, double largeur, double hauteur, Couleur couleur)
    : Formes{coords, couleur}, m_largeur{largeur}, m_hauteur{hauteur}//, m_couleur{couleur}
{}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Rectangle qui sont sa largeur, sa hauteur et sa couleur
void Rectangle::afficher() const {
    m_coords.afficher();
    std::cout << "Largeur x Hauteur: " << m_largeur << " x " << m_hauteur << std::endl;
    std::cout << "Couleur: " << (std::string) m_couleur << std::endl << std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Rectangle::dessiner(Svgfile &svgout) {
    svgout.addRectangle(m_coords.getX(), m_coords.getY(), m_largeur, m_hauteur, m_couleur);
}

/// Fonction qui cherche et retourne la variable Largeur de la classe Rectangle
double Rectangle::getLargeur() const {
    return m_largeur;
}

/// Fonction qui cherche et retourne la variable Hauteur de la classe Rectangle
double Rectangle::getHauteur() const {
    return m_hauteur;
}

/// Fonction qui donne une valeur à la variable Largeur de la classe Rectangle
void Rectangle::setLargeur(double largeur) {
    m_largeur = largeur;
}

/// Fonction qui donne une valeur à la variable Hauteur de la classe Rectangle
void Rectangle::setHauteur(double hauteur) {
    m_hauteur = hauteur;
}

/// Fonction qui permet de modifier la taille du
///Rectangle en modifiant sa largeur et sa hauteur
void Rectangle::Zoom(double coeff) {
    this->setLargeur(coeff * m_largeur);
    this->setHauteur(coeff * m_hauteur);
}

Rectangle::~Rectangle() {

}


