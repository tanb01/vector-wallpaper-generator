#ifndef SOL_H_INCLUDED
#define SOL_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/ellipse.h"

///classe dérivée d'Environnment instanciable
///Les classes virtuelles pures déclarées dans Environnement sont implémentées dans le .cpp de la classe
///Sol est composée de la classe Ellipse
class Sol: public Environnement
{
    ///Méthodes : Déclaration
public:
    Sol(std::mt19937& rg);

    virtual void afficher() const;
    virtual void dessiner(Svgfile& svgout);

    virtual void Translater(double coeff);
    virtual void TranslaterX(double consta);
    virtual void TranslaterY(double consta);

    virtual void Zoom(double coeff);

    virtual void VarColFonc(Heure& heure);

    ~Sol();

    ///Attributs : Déclaration
private:
    Ellipse m_sol;
};

#endif // SOL_H_INCLUDED
