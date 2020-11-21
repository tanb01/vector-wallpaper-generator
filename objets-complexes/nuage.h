#ifndef NUAGE_H_INCLUDED
#define NUAGE_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/ellipse.h"
#include "../primitives/rectangle.h"

/// D�claration d'un type "Nuage" qui h�rite de la classe "Environnement"
///Lune est compos�e de la classe Ellipse et Rectangle
class Nuage : public Environnement {
  ///Methodes : d�claration
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

  /// Attributs : d�claration
 private:
  Ellipse m_nuage1;
  Ellipse m_nuage2;
  Ellipse m_nuage3;

};

#endif // NUAGE_H_INCLUDED
