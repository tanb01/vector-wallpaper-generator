#ifndef NUAGE_H_INCLUDED
#define NUAGE_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/ellipse.h"
#include "../primitives/rectangle.h"

/// Déclaration d'un type "Nuage" qui hérite de la classe "Environnement"
///Lune est composée de la classe Ellipse et Rectangle
class Nuage : public Environnement {
  ///Methodes : déclaration
 public:
  Nuage(std::mt19937 &rg);

  virtual void afficher() const;
  virtual void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);

  ~Nuage();

  /// Attributs : déclaration
 private:
  Ellipse m_nuage1;
  Ellipse m_nuage2;
  Ellipse m_nuage3;

};

#endif // NUAGE_H_INCLUDED
