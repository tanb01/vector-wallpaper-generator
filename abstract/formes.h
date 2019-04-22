#ifndef FORMES_H_INCLUDED
#define FORMES_H_INCLUDED

#include "../svg/coords.h"
#include "../svg/couleur.h"
#include "../svg/svgfile.h"

///classe abstraite et mere des classes rectangle, cercle, etc...
///fais hériter une couleur et des coordonnées sera utilisé dans leur fonction addRect... pour dessiner la figure a un certain endroit

///et a pour méthodes virtuelles pures afficher dessiner et le zoom qui changent selon la forme
///donc pas implémentées dans le formes.cpp

///fais aussi hériter les méthodes de translation, les accesseurs et mutateurs des classes Couleur et Coords
/// qui sont les mêmes pour toutes les classes filles
class Formes
{
    ///Méthodes : déclaration
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

    ///Attributs : déclaration
protected:
    Coords m_coords;
    Couleur m_couleur;
};

#endif // FORMES_H_INCLUDED
