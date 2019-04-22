#ifndef SOL_H_INCLUDED
#define SOL_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/ellipse.h"

///classe d�riv�e d'Environnment instanciable
///Les classes virtuelles pures d�clar�es dans Environnement sont impl�ment�es dans le .cpp de la classe
///Sol est compos�e de la classe Ellipse
class Sol: public Environnement
{
    ///M�thodes : D�claration
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

    ///Attributs : D�claration
private:
    Ellipse m_sol;
};

#endif // SOL_H_INCLUDED
