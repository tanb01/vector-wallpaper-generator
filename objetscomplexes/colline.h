#ifndef COLLINE_H_INCLUDED
#define COLLINE_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/ellipse.h"

/// Déclaration d'un type "Colline" qui hérite de la classe "Environnement"
///Colline est composé de la classe Ellipse
class Colline : public Environnement {
  ///Methodes : déclaration
 public:
  Colline(std::mt19937 &rg);

  virtual void afficher() const;
  virtual void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);

  ~Colline();

  /// Attributs : déclaration
 private:
  Ellipse m_colline;
};

#endif // COLLINE_H_INCLUDED
