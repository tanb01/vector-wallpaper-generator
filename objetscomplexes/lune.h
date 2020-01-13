#ifndef LUNE_H_INCLUDED
#define LUNE_H_INCLUDED

#include "../interface/astre.h"
#include "../primitives/cercle.h"

/// D�claration d'un type "Lune" qui h�rite de la classe "Astre"
///Lune est compos�e de la classe Cercle
class Lune : public Astre {
  ///Methodes : d�claration
 public:
  Lune(std::mt19937 &rg);

  virtual void afficher() const;
  virtual void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double const);

  virtual void VarColFonc(Heure &heure);

  ~Lune();

  /// Attributs : d�claration
 private:
  Cercle m_lune;
  Cercle m_croissant;
};

#endif // LUNE_H_INCLUDED
