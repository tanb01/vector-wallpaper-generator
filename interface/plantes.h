#ifndef PLANTES_H_INCLUDED
#define PLANTES_H_INCLUDED

#include "../abstract/environnement.h"

///Sous catégorie d'objets composite ici les plantes
///Classe mère d'arbres champignon et fleur herbe
class Plantes : public Environnement {
  ///Methodes : déclaration
 public:
  Plantes(Coords coords);
};

#endif // PLANTES_H_INCLUDED
