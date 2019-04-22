#ifndef CIEL_H_INCLUDED
#define CIEL_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/rectangle.h"

///Classe dérivée d'Environnment instanciable
///Les classes virtuelles pures déclarées dans Environnement sont implémentées dans le .cpp de la classe
///Ciel est composée de la classe Rectangle
class Ciel: public Environnement
{
public:
    ///Méthodes : Déclaration
    Ciel(std::mt19937& rg);

    virtual void afficher() const;
    virtual void dessiner(Svgfile& svgout);

    virtual void Translater(double coeff);
    virtual void TranslaterX(double consta);
    virtual void TranslaterY(double consta);

    virtual void VarColFonc(Heure &heure);

    ~Ciel();

    ///Attributs : Déclaration
private:
    Rectangle m_ciel;
};

#endif // CIEL_H_INCLUDED
