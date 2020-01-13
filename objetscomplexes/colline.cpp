#include "colline.h"

///Constructeur de Colline qui appel le constructeur de Environnement et d'Ellipse
///les coordonnées principales dépendent de l'intervalle Min=600 et Max=700 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonnées de Colline dépendent elle de la coordonnée principale
Colline::Colline(std::mt19937 &rg)
    : Environnement{{util::alea(0, 1366, rg), util::alea(600, 700, rg)}},
      m_colline{m_coords, util::alea(400, 500, rg), 300,
          {util::alea(50, 154, rg), util::alea(100, 205, rg), util::alea(0, 50, rg)}} {}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Colline
void Colline::afficher() const {
    std::cout << "Colline was created" << std::endl;
    m_colline.afficher();
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Colline::dessiner(Svgfile &svgout) {
    //{34, 139, 34}
    m_colline.dessiner(svgout);
}

///fonction qui permet de deplacer l'objet
void Colline::Translater(double coeff) {
    m_colline.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Colline::TranslaterX(double consta) {
    m_colline.TranslaterX(consta);
}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Colline::TranslaterY(double consta) {
    m_colline.TranslaterY(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Colline::Zoom(double coeff) {
    m_colline.Zoom(coeff);
}

void Colline::VarColFonc(Heure &heure) {

}

///Destructeur de Colline
Colline::~Colline() {
    std::cout << "Colline was destroyed" << std::endl;
    std::cout << std::endl;
}


