#include "arbre.h"

///Constructeur d'arbre qui appel le constructeur de Plante, de Triangle et de Cercle
///les coordonnées principales dépendent de l'intervalle ex: en Y Min=650 et Max=750 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonées du tronc et des feuilles dépendent elle de la coordonnée principale
Arbre::Arbre(std::mt19937& rg)
    : Plantes{{util::alea(0, 1366, rg), util::alea(650, 750, rg)}},
m_tronc{{m_coords.getX(), m_coords.getY()-160},{m_coords.getX()+util::alea(5, 10, rg), m_coords.getY()+util::alea(5, 10, rg)},{m_coords.getX()-util::alea(5, 10, rg), m_coords.getY()+util::alea(5, 10, rg)},{160, 82, 45}},
m_otronc{m_tronc.getSommets()[0],m_tronc.getSommets()[1],{m_coords.getX(),m_coords.getY()+util::alea(5, 10, rg)},{160, 82, 45}},
m_feuilles{{m_coords.getX(), m_coords.getY()-160}, util::alea(40, 74, rg), {util::alea(0, 54, rg), util::alea(100, 170, rg), util::alea(0, 54, rg)}},
m_ofeuilles{{m_feuilles.getCoords().getX()+10, m_feuilles.getCoords().getY()}, m_feuilles.getRayon()*0.9, {0,0,0}}
{}

///Affichage des coords, du rayon de l'arbres créé
void Arbre::afficher() const
{
    std::cout << "Arbre was created "<< std::endl;
    m_coords.afficher();
    std::cout << "Rayon: " << m_feuilles.getRayon() << std::endl<< std::endl;
}

///Appel a la fonction dessiner des classes Triangle et Cercle
void Arbre::dessiner(Svgfile& svgout)
{
    m_feuilles.dessiner(svgout);
    svgout.addDisk(m_ofeuilles.getCoords().getX(),m_ofeuilles.getCoords().getY(), m_ofeuilles.getRayon(), makeRGB(0,0,0), 0.5);
    m_tronc.dessiner(svgout);
    svgout.addPolygon(m_otronc.getSommets(), makeRGB(0,0,0), 0.5);

}

///Appel a la fonction translater des classes Triangle et Cercle
void Arbre::Translater(double coeff)
{
    m_tronc.Translater(coeff);
    m_otronc.Translater(coeff);
    m_feuilles.Translater(coeff);
    m_ofeuilles.Translater(coeff);
}

///Appel a la fonction TranslaterX des classes Triangle et Cercle
void Arbre::TranslaterX(double consta)
{
    m_tronc.TranslaterX(consta);
    m_otronc.TranslaterX(consta);
    m_feuilles.TranslaterX(consta);
    m_ofeuilles.TranslaterX(consta);
}
///Appel a la fonction TranslaterY des classes Triangle et Cercle
void Arbre::TranslaterY(double consta)
{
    m_tronc.TranslaterY(consta);
    m_otronc.TranslaterY(consta);
    m_feuilles.TranslaterY(consta);
    m_ofeuilles.TranslaterY(consta);
}

///Appel a la fonction Zoom des classes Triangle et Cercle
void Arbre::Zoom(double coeff)
{
    m_tronc.Zoom(coeff);
    m_otronc.Zoom(coeff);
    m_feuilles.Zoom(coeff);
    m_ofeuilles.Zoom(coeff);
}
///Variation de la couleur en fonction de l'heure
void Arbre::VarColFonc(Heure& heure)
{
        ///De 7h a 12h
    if(heure.getHeure()>=7&&heure.getHeure()<12)
    {
    }
      ///De 12h a 17h
    if(heure.getHeure()>=12&&heure.getHeure()<17)
     {
     }
        ///De 17h a 20h
    if(heure.getHeure()>=17&&heure.getHeure()<20)
    {
    }
        ///De 20h a 23h     00h etant le milieu de la nuit
    if(heure.getHeure()>=20&&heure.getHeure()<=23)
    {
    }
        ///De 00h a 7h
    if(heure.getHeure()>=0&&heure.getHeure()<7)
    {
    }
}

///Destructeur d'arbre
Arbre::~Arbre()
{
    std::cout << "Arbre was destroyed" << std::endl;
    std::cout <<std::endl;
}
