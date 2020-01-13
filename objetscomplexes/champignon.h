#ifndef CHAMPIGNON_H_INCLUDED
#define CHAMPIGNON_H_INCLUDED

#include "../interface/plantes.h"
#include "../primitives/triangle.h"
#include "../primitives/ellipse.h"
#include "../primitives/cercle.h"

/// D�claration d'un type "Champignon" qui h�rite de la classe "Plantes"
///Champignon est compos� de la classe Triangle, Ellipse et Cercle
class Champignon : public Plantes {
  ///Methodes : d�claration
 public:
  Champignon(std::mt19937 &rg);

  void afficher() const;
  void dessiner(Svgfile &svgout);

  void Translater(double coeff);
  void TranslaterX(double consta);
  void TranslaterY(double consta);

  void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);
  ~Champignon();

  ///Attributs : d�claration
 private:
  Cercle m_tete;
  Ellipse m_bas;
  Triangle m_tige;
};

#endif // CHAMPIGNON_H_INCLUDED
