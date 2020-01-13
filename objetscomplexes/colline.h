#ifndef COLLINE_H_INCLUDED
#define COLLINE_H_INCLUDED

#include "../abstract/environnement.h"
#include "../primitives/ellipse.h"

/// D�claration d'un type "Colline" qui h�rite de la classe "Environnement"
///Colline est compos� de la classe Ellipse
class Colline : public Environnement {
  ///Methodes : d�claration
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

  /// Attributs : d�claration
 private:
  Ellipse m_colline;
};

#endif // COLLINE_H_INCLUDED
