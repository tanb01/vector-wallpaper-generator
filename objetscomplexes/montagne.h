#ifndef MONTAGNE_H_INCLUDED
#define MONTAGNE_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/triangle.h"

/// Déclaration d'un type "Montagne" qui hérite de la classe "Environnement"
///Montagne est composé de la classe Triangle
class Montagne : public Environnement {
  ///Methodes : déclaration
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

  /// Attributs : déclaration
 private:
  Triangle m_montagne1;
  Triangle m_montagne2;
};

#endif // MONTAGNE_H_INCLUDED
