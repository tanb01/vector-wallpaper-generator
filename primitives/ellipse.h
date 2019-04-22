#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED

#include "../abstract/formes.h"

/// Déclaration d'un type "Ellipse" qui hérite de la classe "Formes"
class Ellipse : public Formes
{
///Methodes : déclaration
public:
    Ellipse(Coords coords, double rayonx, double rayony, Couleur couleur);

    virtual void afficher() const;
    virtual void dessiner(Svgfile& svgout);

    double getRayonX() const;
    double getRayonY() const;

    void setRayonX(double rayonx);
    void setRayonY(double rayony);

    virtual void Zoom(double coeff);

/// Attributs : déclaration
private:
    double m_rayonx;
    double m_rayony;
};

#endif // ELLIPSE_H_INCLUDED
