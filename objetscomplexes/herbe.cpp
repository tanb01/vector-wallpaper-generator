#include "herbe.h"

///Constructeur de Herbe qui appel le constructeur de Plantes et de Triangle
///les coordonnées principales dépendent de l'intervalle Min=600.0 et Max=750.0 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonnées de Herbe dépendent elle de la coordonnée principale
Herbe::Herbe(std::mt19937 &rg)
    : Plantes{{util::alea(0.0, 1366.0, rg), util::alea(600.0, 750.0, rg)}},
      m_herbe1{{m_coords}, {m_coords.getX() + 3, m_coords.getY() - 5}, {m_coords.getX() + 6, m_coords.getY()},
          {util::alea(74, 124, rg), util::alea(102, 252, rg), util::alea(0, 24, rg)}},
      m_herbe2{{m_coords.getX() - 10, m_coords.getY() + 5}, {m_coords.getX() - 5, m_coords.getY() + 5},
          {m_coords.getX() - 3, m_coords.getY() - 5},
          {util::alea(74, 124, rg), util::alea(102, 252, rg), util::alea(0, 24, rg)}},
      m_herbe3{{m_coords.getX() + 10, m_coords.getY() + 5}, {m_coords.getX() + 18, m_coords.getY() + 5},
          {m_coords.getX() + 16, m_coords.getY()},
          {util::alea(74, 124, rg), util::alea(102, 252, rg), util::alea(0, 24, rg)}} {}//124, 252, 0 //85, 107, 47

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Herbe
void Herbe::afficher() const {
    std::cout << "Herbe was created " << std::endl;
    m_coords.afficher();
    m_herbe1.getCoords().afficher();
    m_herbe2.getCoords().afficher();
    m_herbe3.getCoords().afficher();
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Herbe::dessiner(Svgfile &svgout) {
    m_herbe1.dessiner(svgout);
    m_herbe2.dessiner(svgout);
    m_herbe3.dessiner(svgout);
}

///fonction qui permet de deplacer l'objet
void Herbe::Translater(double coeff) {
    m_herbe1.Translater(coeff);
    m_herbe2.Translater(coeff);
    m_herbe3.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Herbe::TranslaterX(double consta) {
    m_herbe1.TranslaterX(consta);
    m_herbe2.TranslaterX(consta);
    m_herbe3.TranslaterX(consta);
}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Herbe::TranslaterY(double consta) {
    m_herbe1.TranslaterY(consta);
    m_herbe2.TranslaterY(consta);
    m_herbe3.TranslaterY(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Herbe::Zoom(double coeff) {
    m_herbe1.Zoom(coeff);
    m_herbe2.Zoom(coeff);
    m_herbe3.Zoom(coeff);
}

///Destructeur de Herbe
void Herbe::VarColFonc(Heure &heure) {

}
