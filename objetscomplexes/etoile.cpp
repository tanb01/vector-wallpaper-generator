#include "etoile.h"

///Constructeur de Etoile qui appel le constructeur de Astre et de Triangle
///les coordonnées principales dépendent de l'intervalle Min=0 et Max=400 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonées de Etoile dépendent elle de la coordonnée principale(qui represente le centre de l'etoile)
Etoile::Etoile(std::mt19937& rg)
	: Astre{{util::alea(0, 1366, rg), util::alea(0, 400, rg)}},
m_triangle1{{m_coords.getX(),m_coords.getY()-(10)}, {m_coords.getX()+(5),m_coords.getY()},{m_coords.getX()-(5),m_coords.getY()},  {255, 250, 205}},
m_triangle2{{m_coords.getX()+(10), m_coords.getY()}, {m_coords.getX(),m_coords.getY()-(5)},{m_coords.getX(),m_coords.getY()+(5)},  {255, 250, 205}},
m_triangle3{{m_coords.getX(),m_coords.getY()+(10)}, m_triangle1.getSommets()[1],m_triangle1.getSommets()[2],  {255, 250, 205}},
m_triangle4{{m_coords.getX()-(10), m_coords.getY()}, m_triangle2.getSommets()[1],m_triangle2.getSommets()[2],  {255, 250, 205}}
{}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Etoile
void Etoile::afficher() const
{
    std::cout << "Etoile was created "<< std::endl;
    m_coords.afficher();
    std::cout << std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Etoile::dessiner(Svgfile& svgout)
{
    m_triangle1.dessiner(svgout);
    m_triangle2.dessiner(svgout);
    m_triangle3.dessiner(svgout);
    m_triangle4.dessiner(svgout);

///Apres avoir dessiner l'Etoile dans le svg.file on rajoute des effets de brillance
	///Bonus
	svgout.addDisk(m_coords.getX(), m_coords.getY(), 2.5*(m_triangle1.getSommets()[1].getX()-m_coords.getX()), makeRGB(255,250,205), 0.2);
}


///fonction qui permet de deplacer l'objet
void Etoile::Translater(double coeff)
{
    m_triangle1.Translater(coeff);
    m_triangle2.Translater(coeff);
    m_triangle3.Translater(coeff);
    m_triangle4.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Etoile::TranslaterX(double consta)
{
    m_triangle1.Translater(consta);
    m_triangle2.Translater(consta);
    m_triangle3.Translater(consta);
    m_triangle4.Translater(consta);

}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Etoile::TranslaterY(double consta)
{
    m_triangle1.Translater(consta);
    m_triangle2.Translater(consta);
    m_triangle3.Translater(consta);
    m_triangle4.Translater(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Etoile::Zoom(double coeff)
{
    m_triangle1.Zoom(coeff);
    m_triangle2.Zoom(coeff);
    m_triangle3.Zoom(coeff);
    m_triangle4.Zoom(coeff);
}

void Etoile::VarColFonc(Heure& heure)
{

}

///Destructeur de Nuage
Etoile::~Etoile()
{
    std::cout << "Etoile was destroyed" << std::endl;
    std::cout <<std::endl;
}

