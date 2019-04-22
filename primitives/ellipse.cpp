#include "ellipse.h"

/// Constructeur qui prend en paramêtres quatre variables
Ellipse::Ellipse(Coords coords, double rayonx, double rayony, Couleur couleur)
: Formes{coords, couleur}, m_rayonx{rayonx}, m_rayony{rayony}//, m_couleur{couleur}
{}


/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Ellipse qui sont son rayonx, son rayony et sa couleur
void Ellipse::afficher() const
{
    m_coords.afficher();
    std::cout << "RayonX: " << m_rayonx << std::endl;
    std::cout << "RayonY: "<< m_rayony << std::endl;
    std::cout << "Couleur: " << (std::string)m_couleur << std::endl<< std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Ellipse::dessiner(Svgfile& svgout)
{
    svgout.addEllipse(m_coords.getX(), m_coords.getY(), m_rayonx, m_rayony, m_couleur);
}

/// Fonction qui cherche et retourne la variable RayonX de la classe Ellipse
double Ellipse::getRayonX() const
{
    return m_rayonx;
}

/// Fonction qui cherche et retourne la variable RayonY de la classe Ellipse
double Ellipse::getRayonY() const
{
    return m_rayony;
}

/// Fonction qui donne une valeur à la variable RayonX de la classe Ellipse
void Ellipse::setRayonX(double rayonx)
{
    m_rayonx = rayonx;
}

/// Fonction qui donne une valeur à la variable RayonY de la classe Ellipse
void Ellipse::setRayonY(double rayony)
{
    m_rayony = rayony;
}

/// Fonction qui permet de modifier la taille de
///L'ellipse en modifiant son rayonx et son rayony
void Ellipse::Zoom(double coeff)
{
    this->setRayonX(coeff*m_rayonx);
    this->setRayonY(coeff*m_rayony);
}


