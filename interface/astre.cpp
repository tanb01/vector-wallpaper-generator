#include "astre.h"

///Constructeur utilis� directement par Soleil, Lune, Etoile
///Attention forme non instanciable seulement par le biais de ses classes filles

Astre::Astre(Coords coords)
    : Environnement{coords} {}

