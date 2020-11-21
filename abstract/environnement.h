#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include "../svg/coords.h"
#include "../svg/svgfile.h"
#include "../extensions/heure.h"

///Est compos� de la classe Coords, elle l'a fait h�riter en protected
///Ces coordonn�es sont les coordonn�es principales de l'objet
///classe m�re de tous les objets composites non instanciable
///fais h�riter les m�thodes virtuelles pures afficher dessiner translater etc..
///car diff�rents pour chacun des objets composites
///seul les mutateurs et accesseur de Coords sont les m�mes pour chacun des objets composites
class Environnement {
  ///M�thodes : d�claration
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

  ///Attributs : d�claration
 protected:
  Coords m_coords;
};

#endif // ENVIRONNEMENT_H_INCLUDED
