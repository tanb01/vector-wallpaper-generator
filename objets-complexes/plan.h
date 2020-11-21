#ifndef PLAN_H_INCLUDED
#define PLAN_H_INCLUDED

#include <vector>
#include <iterator>
#include "../util/util.h"
#include "../svg/svgfile.h"
#include "../svg/couleur.h"
#include <algorithm>
#include "../abstract/environnement.h"

///La classe Plan est composée de D'environnements(Arbres, fleur, ciel ...) stockés dans un vecteur Environnement*
class Plan {
  ///Méthodes : Déclaration
 public:
  Plan();

  void afficher() const;
  void dessiner(Svgfile &svgout);

  void remplirEnvironnement(std::vector<Environnement *> &objets);
  void viderEnvironnement();

  void trier();

  ///Attributs : Déclaration
 private:
  std::vector<Environnement *> m_objets;
};

#endif // PLAN_H_INCLUDED
