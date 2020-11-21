#include "plan.h"

Plan::Plan() {}

void Plan::remplirEnvironnement(std::vector<Environnement *> &objets) {
    ///Méthode qui remplis le plan d'objets diverses dont leur classe mère est Environnement
    for (auto ptr: objets)
        m_objets.push_back(ptr);
}

///Appel des méthodes afficher des classes composites (arbres, fleur, ciel ...)
void Plan::afficher() const {

    std::cout << "Plan was created " << std::endl;
    for (auto ptr: m_objets)
        ptr->afficher();
}

///Appel des méthodes dessiner des classes composites (arbres, fleur, ciel ...)
void Plan::dessiner(Svgfile &svgout) {

    for (auto ptr: m_objets)
        ptr->dessiner(svgout);
}

///Vider le vecteur implication la déallocation de la mémoire ou est stockés l'objet
void Plan::viderEnvironnement() {
    for (auto ptr:m_objets)
        delete ptr;
    m_objets.clear();
}

///Sous programme qui compare les coordonées Y  return true si a < b
bool Fonctinf(Environnement *a, Environnement *b) {
    return (a->getCoords().getY() < b->getCoords().getY());
}

///Méthode de trie en utilisant la fonction std::sort de la bibliothque <algorithm>
///Trie par ordre croissant le vecteur m_objet du début à la fin
void Plan::trier() {
    std::sort(m_objets.begin(), m_objets.end(), Fonctinf);
}
