#ifndef PLANTES_H_INCLUDED
#define PLANTES_H_INCLUDED

#include "../abstract/environnement.h"

///Sous cat�gorie d'objets composite ici les plantes
///Classe m�re d'arbres champignon et fleur herbe
class Plantes : public Environnement {
  ///Methodes : d�claration
 public:
  Plantes(Coords coords);
};

#endif // PLANTES_H_INCLUDED
