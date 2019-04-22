#ifndef CIEL_H_INCLUDED
#define CIEL_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/rectangle.h"

///Classe d�riv�e d'Environnment instanciable
///Les classes virtuelles pures d�clar�es dans Environnement sont impl�ment�es dans le .cpp de la classe
///Ciel est compos�e de la classe Rectangle
class Ciel: public Environnement
{
public:
    ///M�thodes : D�claration
    Ciel(std::mt19937& rg);

    virtual void afficher() const;
    virtual void dessiner(Svgfile& svgout);

    virtual void Translater(double coeff);
    virtual void TranslaterX(double consta);
    virtual void TranslaterY(double consta);

    virtual void VarColFonc(Heure &heure);

    ~Ciel();

    ///Attributs : D�claration
private:
    Rectangle m_ciel;
};

#endif // CIEL_H_INCLUDED
