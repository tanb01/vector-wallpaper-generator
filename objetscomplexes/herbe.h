#ifndef HERBE_H_INCLUDED
#define HERBE_H_INCLUDED

#include "../interface/plantes.h"
#include "../primitives/triangle.h"

/// Déclaration d'un type "Herbe" qui hérite de la classe "Plantes"
///Herbe est composé de la classe Triangle
class Herbe : public Plantes {
  ///Methodes : déclaration
 public:
  Herbe(std::mt19937 &rg);

  void afficher() const;
  void dessiner(Svgfile &svgout);

  void Translater(double coeff);
  void TranslaterX(double consta);
  void TranslaterY(double consta);

  void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);

  /// Attributs : déclaration
 private:
  Triangle m_herbe1;
  Triangle m_herbe2;
  Triangle m_herbe3;
};
#endif // HERBE_H_INCLUDED
