#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "../interface/plantes.h"
#include "../primitives/cercle.h"
#include "../primitives/triangle.h"

///Classe fille de Plantes instanciable
///Les classes virtuelles pures d�clar�es dans Environnement sont impl�ment�es dans le .cpp de la classe
///Arbre est compos�e de la classe Triangle et Cercle

class Arbre: public Plantes
{
    ///M�thodes : d�claration
public:
    Arbre(std::mt19937& rg);

    void afficher() const;
    void dessiner(Svgfile& svgout);

    virtual void Translater(double coeff);
    virtual void TranslaterX(double consta);
    virtual void TranslaterY(double consta);

    virtual void Zoom(double coeff);

    virtual void VarColFonc(Heure& heure);

    ~Arbre();

    ///Attributs : d�claration
private:
    Triangle m_tronc;
    Triangle m_otronc;
    Cercle m_feuilles;
    Cercle m_ofeuilles;
};

#endif // ARBRE_H_INCLUDED

