#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include "../svg/coords.h"
#include "../svg/svgfile.h"
#include "../extensions/heure.h"

///Est composé de la classe Coords, elle l'a fait hériter en protected
///Ces coordonnées sont les coordonnées principales de l'objet
///classe mère de tous les objets composites non instanciable
///fais hériter les méthodes virtuelles pures afficher dessiner translater etc..
///car différents pour chacun des objets composites
///seul les mutateurs et accesseur de Coords sont les mêmes pour chacun des objets composites
class Environnement {
  ///Méthodes : déclaration
 public:
  Environnement(Coords coords = {0, 0});

  void setCoords(Coords coords);
  Coords getCoords() const;

  virtual void afficher() const = 0;
  virtual void dessiner(Svgfile &svgout) = 0;

  virtual void Translater(double coeff) = 0;
  virtual void TranslaterX(double consta) = 0;
  virtual void TranslaterY(double consta) = 0;

  virtual void VarColFonc(Heure &heure) = 0;

  ///Attributs : déclaration
 protected:
  Coords m_coords;
};

#endif // ENVIRONNEMENT_H_INCLUDED
