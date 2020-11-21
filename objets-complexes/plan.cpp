#include "plan.h"

Plan::Plan() {}

void Plan::remplirEnvironnement(std::vector<Environnement *> &objets) {
    ///M�thode qui remplis le plan d'objets diverses dont leur classe m�re est Environnement
    for (auto ptr: objets)
        m_objets.push_back(ptr);
}

///Appel des m�thodes afficher des classes composites (arbres, fleur, ciel ...)
void Plan::afficher() const {

    std::cout << "Plan was created " << std::endl;
    for (auto ptr: m_objets)
        ptr->afficher();
}

///Appel des m�thodes dessiner des classes composites (arbres, fleur, ciel ...)
void Plan::dessiner(Svgfile &svgout) {

    for (auto ptr: m_objets)
        ptr->dessiner(svgout);
}

///Vider le vecteur implication la d�allocation de la m�moire ou est stock�s l'objet
void Plan::viderEnvironnement() {
    for (auto ptr:m_objets)
        delete ptr;
    m_objets.clear();
}

///Sous programme qui compare les coordon�es Y  return true si a < b
bool Fonctinf(Environnement *a, Environnement *b) {
    return (a->getCoords().getY() < b->getCoords().getY());
}

///M�thode de trie en utilisant la fonction std::sort de la bibliothque <algorithm>
///Trie par ordre croissant le vecteur m_objet du d�but � la fin
void Plan::trier() {
    std::sort(m_objets.begin(), m_objets.end(), Fonctinf);
}
