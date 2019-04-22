#ifndef FORMES_H_INCLUDED
#define FORMES_H_INCLUDED

#include "../svg/coords.h"
#include "../svg/couleur.h"
#include "../svg/svgfile.h"

///classe abstraite et mere des classes rectangle, cercle, etc...
///fais h�riter une couleur et des coordonn�es sera utilis� dans leur fonction addRect... pour dessiner la figure a un certain endroit

///et a pour m�thodes virtuelles pures afficher dessiner et le zoom qui changent selon la forme
///donc pas impl�ment�es dans le formes.cpp

///fais aussi h�riter les m�thodes de translation, les accesseurs et mutateurs des classes Couleur et Coords
/// qui sont les m�mes pour toutes les classes filles
class Formes
{
    ///M�thodes : d�claration
public:
    Formes(Coords coords, Couleur couleur={0,0,0});
    virtual ~Formes() = default;

    virtual void afficher()const = 0;
    virtual void dessiner(Svgfile& svgout)=0;

    virtual void Translater(double coeff);
    virtual void TranslaterX(double consta);
    virtual void TranslaterY(double consta);

    virtual void Zoom(double coeff)=0;

    Coords getCoords() const;
    void setCoords(Coords coords);

    virtual Couleur getCouleur() const;

    virtual void setCouleur(Couleur couleur);

    ///Attributs : d�claration
protected:
    Coords m_coords;
    Couleur m_couleur;
};

#endif // FORMES_H_INCLUDED
