#ifndef SOLEIL_H_INCLUDED
#define SOLEIL_H_INCLUDED

#include "../interface/astre.h"
#include "../primitives/cercle.h"

/// D�claration d'un type "Soleil" qui h�rite de la classe "Astre"
///Soleil est compos�e de la classe Cercle
class Soleil : public Astre {
  ///Methodes : d�claration
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

  /// Attributs : d�claration
 private:
  Cercle m_soleil;
};

#endif // SOLEIL_H_INCLUDED
