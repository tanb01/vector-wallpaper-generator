#include "champignon.h"

///Constructeur de Champignon qui appel le constructeur de Plantes, de Triangle, d'Ellipse et de Cercle
///les coordonnées principales dépendent de l'intervalle Min=600.0 et Max=750.0 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonnées de Champignon dépendent elle de la coordonnée principale(qui represente le centre de la tete)
Champignon::Champignon(std::mt19937 &rg)
    : Plantes{{util::alea(0.0, 1366.0, rg), util::alea(600.0, 750.0, rg)}},
      m_tete{{m_coords.getX(), m_coords.getY() - 15}, util::alea(5, 10, rg), {225, 42, 42}},//164
      m_bas{{m_coords.getX(), m_coords.getY() - 11}, m_tete.getRayon(), m_tete.getRayon() * 0.5, {225, 42, 42}},
      m_tige{{m_coords.getX(), m_coords.getY() - 15},
          {m_coords.getX() + util::alea(1, 3, rg), m_coords.getY() + util::alea(0, 2, rg)},
          {m_coords.getX() - util::alea(1, 3, rg), m_coords.getY() + util::alea(0, 2, rg)}, {245, 245, 220}} {}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Champignon
void Champignon::afficher() const {
    std::cout << "Champignon was created " << std::endl;
    m_coords.afficher();
    m_tige.getCoords().afficher();
    m_tete.getCoords().afficher();
    m_bas.getCoords().afficher();
    std::cout << std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Champignon::dessiner(Svgfile &svgout) {
    m_tige.dessiner(svgout);
    m_tete.dessiner(svgout);
    m_bas.dessiner(svgout);
}

///fonction qui permet de deplacer l'objet
void Champignon::Translater(double coeff) {
    m_tete.Translater(coeff);
    m_bas.Translater(coeff);
    m_tige.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Champignon::TranslaterX(double consta) {
    m_tete.TranslaterX(consta);
    m_bas.TranslaterX(consta);
    m_tige.TranslaterX(consta);
}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Champignon::TranslaterY(double consta) {
    m_tete.TranslaterY(consta);
    m_bas.TranslaterY(consta);
    m_tige.TranslaterY(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Champignon::Zoom(double coeff) {
    m_tete.Zoom(coeff);
    m_bas.Zoom(coeff);
    m_tige.Zoom(coeff);
}

void Champignon::VarColFonc(Heure &heure) {

}

///Destructeur de Champignon
Champignon::~Champignon() {
    std::cout << "Champignon was destroyed" << std::endl;
    std::cout << std::endl;
}
