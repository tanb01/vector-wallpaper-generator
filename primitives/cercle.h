#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED

#include "../abstract/formes.h"

/// D�claration d'un type "Cercle" qui h�rite de la classe "Formes"
class Cercle : public Formes
{
    ///Methodes : d�claration
public:
    Cercle(Coords coords, double rayon, Couleur couleur);

    virtual void afficher() const;
    virtual void dessiner(Svgfile& svgout);

    double getRayon() const;
    void setRayon(double rayon);

    virtual void Zoom(double coeff);

    /// Attributs : d�claration
private:
    double m_rayon;
};

#endif // CERCLE_H_INCLUDED
