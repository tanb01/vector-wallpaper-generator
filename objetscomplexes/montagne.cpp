#include "montagne.h"

///Constructeur de Montagne qui appel le constructeur de Environnement et de Triangle
///les coordonnées principales dépendent de l'intervalle Min=500 et Max=700 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonnées de Montagne dépendent elle de la coordonnée principale
Montagne::Montagne(std::mt19937& rg)
    : Environnement{{util::alea(0, 1366, rg), util::alea(500, 700, rg)}},
m_montagne1{{m_coords.getX(), m_coords.getY()-util::alea(200, 450, rg)},
    {m_coords.getX()+ util::alea(100, 200, rg), m_coords.getY()},
    {m_coords.getX()-util::alea(300, 380, rg), m_coords.getY()+(768-m_coords.getY())},
    {util::alea(172, 222, rg), util::alea(134, 184, rg), util::alea(185, 135, rg)}},
m_montagne2{m_montagne1.getSommets()[0], m_montagne1.getSommets()[1], {m_coords.getX(), m_coords.getY()}, {0,0,0}}
{}

Montagne::Montagne(std::mt19937& rg, int &taille_minimum, int &taille_maximum)
    : Environnement{{util::alea(0, 1366, rg), util::alea(500, 700, rg)}},
m_montagne1{{m_coords.getX(), m_coords.getY()-util::alea(taille_minimum, taille_maximum, rg)},
    {m_coords.getX()+ util::alea(100, 200, rg), m_coords.getY()},
    {m_coords.getX()-util::alea(300, 380, rg), m_coords.getY()+(768-m_coords.getY())},
    {util::alea(172, 222, rg), util::alea(134, 184, rg), util::alea(185, 135, rg)}},
m_montagne2{m_montagne1.getSommets()[0], m_montagne1.getSommets()[1], {m_coords.getX(), m_coords.getY()}, {0,0,0}}
{}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Montagne
void Montagne::afficher() const
{
    std::cout << "Montagne was created"<< std::endl;
    m_montagne1.afficher();
    m_montagne2.afficher();
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Montagne::dessiner(Svgfile& svgout)
{
    m_montagne1.dessiner(svgout);
///Apres avoir dessiner la Montagne dans le svg.file on rajoute une ombre
    svgout.addPolygon(m_montagne2.getSommets(), makeRGB(0,0,0), 0.5);
}

///fonction qui permet de deplacer l'objet
void Montagne::Translater(double coeff)
{
    m_montagne1.Translater(coeff);
    m_montagne2.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Montagne::TranslaterX(double consta)
{
    m_montagne1.TranslaterX(consta);
    m_montagne2.TranslaterX(consta);
}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Montagne::TranslaterY(double consta)
{
    m_montagne1.TranslaterY(consta);
    m_montagne2.TranslaterY(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Montagne::Zoom(double coeff)
{
    m_montagne1.Zoom(coeff);
    m_montagne2.Zoom(coeff);
}

void Montagne::VarColFonc(Heure& heure)
{

}

///Destructeur de Montagne
Montagne::~Montagne()
{
    std::cout << "Montagne was destroyed" << std::endl;
    std::cout <<std::endl;
}
