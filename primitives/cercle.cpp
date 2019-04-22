#include "cercle.h"

/// Constructeur qui prend en paramêtres trois variables
Cercle::Cercle(Coords coords, double rayon, Couleur couleur)
    : Formes{coords, couleur}, m_rayon{rayon}
{}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Cercle qui sont son rayon et sa couleur
void Cercle::afficher() const
{
    getCoords().afficher();
    std::cout << "Rayon: " << getRayon() << std::endl;
    std::cout << "Couleur: " << (std::string)getCouleur() << std::endl<< std::endl;
}


/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Cercle::dessiner(Svgfile& svgout)
{
    svgout.addDisk(m_coords.getX(), m_coords.getY(), m_rayon, m_couleur);
}

/// Fonction qui cherche et retourne la variable Rayon de la classe Cercle
double Cercle::getRayon() const
{
    return m_rayon;
}

/// Fonction qui donne une valeur à la variable Rayon de la classe Cercle
void Cercle::setRayon(double rayon)
{
    m_rayon = rayon;
}

/// Fonction qui permet de modifier la taille du
///cercle en modifiant son rayon
void Cercle::Zoom(double coeff)
{
    this->setRayon(coeff*m_rayon);
}

