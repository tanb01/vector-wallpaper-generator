#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "../abstract/formes.h"

/// D�claration d'un type "Rectangle" qui h�rite de la classe "Formes"
class Rectangle : public Formes
{
    ///Methodes : d�claration
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

    /// Attributs : d�claration
private:
    double m_largeur;
    double m_hauteur;
};

#endif // RECTANGLE_H_INCLUDED
