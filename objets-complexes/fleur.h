#ifndef FLEUR_H_INCLUDED
#define FLEUR_H_INCLUDED

#include "../interface/plantes.h"
#include "../primitives/cercle.h"
#include "../primitives/rectangle.h"

///classe dérivée de Plantes, instanciable
///Les classes virtuelles pures déclarées dans Environnement sont implémentées dans le .cpp de la classe
///Ciel est composée des classes Rectangle et Cercle
class Fleur : public Plantes {
  ///Méthodes : Déclaration
 public:
  Fleur(std::mt19937 &rg);

  void afficher() const;
  void dessiner(Svgfile &svgout);

  virtual void Translater(double coeff);
  virtual void TranslaterX(double consta);
  virtual void TranslaterY(double consta);

  virtual void Zoom(double coeff);

  virtual void VarColFonc(Heure &heure);

  ~Fleur();

  ///Attributs : Déclaration
 private:
  Rectangle m_tige;
  Cercle m_centre_fleur;

  Cercle m_petales1;
  Cercle m_petales2;
  Cercle m_petales3;
  Cercle m_petales4;

};

#endif // FLEUR_H_INCLUDED
