#ifndef MONTAGNE_H_INCLUDED
#define MONTAGNE_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/triangle.h"

/// D�claration d'un type "Montagne" qui h�rite de la classe "Environnement"
///Montagne est compos� de la classe Triangle
class Montagne : public Environnement {
  ///Methodes : d�claration
 public:
  Montagne(std::mt19937 &rg);

  Montagne(std::mt19937 &rg, int &taille_minimum, int &taille_maximum);

  virtual void afficher() const;
  virtual void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);

  ~Montagne();

  /// Attributs : d�claration
 private:
  Triangle m_montagne1;
  Triangle m_montagne2;
};

#endif // MONTAGNE_H_INCLUDED
