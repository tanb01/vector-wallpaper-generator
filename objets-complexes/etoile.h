#ifndef ETOILE_H_INCLUDED
#define ETOILE_H_INCLUDED

#include "../interface/astre.h"
#include "../primitives/triangle.h"

/// Déclaration d'un type "Etoile" qui hérite de la classe "Astre"
///Etoile est composée de la classe Triangle
class Etoile : public Astre {
  ///Methodes : déclaration
 public:
  Etoile(std::mt19937 &rg);

  void afficher() const;
  void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double const);

  virtual void VarColFonc(Heure &heure);

  ~Etoile();
  ///Attributs : déclaration
 private:
  Triangle m_triangle1;
  Triangle m_triangle2;
  Triangle m_triangle3;
  Triangle m_triangle4;
};

#endif // ETOILE_H_INCLUDED
