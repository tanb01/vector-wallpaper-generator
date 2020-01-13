#ifndef LUNE_H_INCLUDED
#define LUNE_H_INCLUDED

#include "../interface/astre.h"
#include "../primitives/cercle.h"

/// Déclaration d'un type "Lune" qui hérite de la classe "Astre"
///Lune est composée de la classe Cercle
class Lune : public Astre {
  ///Methodes : déclaration
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

  /// Attributs : déclaration
 private:
  Cercle m_lune;
  Cercle m_croissant;
};

#endif // LUNE_H_INCLUDED
