#ifndef HERBE_H_INCLUDED
#define HERBE_H_INCLUDED

#include "../interface/plantes.h"
#include "../primitives/triangle.h"

/// D�claration d'un type "Herbe" qui h�rite de la classe "Plantes"
///Herbe est compos� de la classe Triangle
class Herbe : public Plantes {
  ///Methodes : d�claration
 public:
  Herbe(std::mt19937 &rg);

  void afficher() const;
  void dessiner(Svgfile &svgout);

  void Translater(double coeff);
  void TranslaterX(double consta);
  void TranslaterY(double consta);

  void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);

  /// Attributs : d�claration
 private:
  Triangle m_herbe1;
  Triangle m_herbe2;
  Triangle m_herbe3;
};
#endif // HERBE_H_INCLUDED
