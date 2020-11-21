#ifndef SOLEIL_H_INCLUDED
#define SOLEIL_H_INCLUDED

#include "../interface/astre.h"
#include "../primitives/cercle.h"

/// Déclaration d'un type "Soleil" qui hérite de la classe "Astre"
///Soleil est composée de la classe Cercle
class Soleil : public Astre {
  ///Methodes : déclaration
 public:
  Soleil(std::mt19937 &rg);

  void afficher() const;
  void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double const);

  virtual void VarColFonc(Heure &heure);

  ~Soleil();

  /// Attributs : déclaration
 private:
  Cercle m_soleil;
};

#endif // SOLEIL_H_INCLUDED
