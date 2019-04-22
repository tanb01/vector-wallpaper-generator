#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "../abstract/formes.h"

/// Déclaration d'un type "Rectangle" qui hérite de la classe "Formes"
class Rectangle : public Formes
{
    ///Methodes : déclaration
public:
    Rectangle(Coords coords, double largeur, double hauteur, Couleur couleur);

    virtual void afficher() const;
    virtual void dessiner(Svgfile& svgout);

    double getLargeur() const;
    double getHauteur() const;

    void setLargeur(double largeur);
    void setHauteur(double hauteur);

    virtual void Zoom(double coeff);

    ~Rectangle();

    /// Attributs : déclaration
private:
    double m_largeur;
    double m_hauteur;
};

#endif // RECTANGLE_H_INCLUDED
