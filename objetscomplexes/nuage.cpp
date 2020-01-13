#include "nuage.h"

///Constructeur de Nuage qui appel le constructeur de Environnement, de Ellipse et de Rectangle
///les coordonnées principales dépendent de l'intervalle Min=0 et Max=200 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonées de Nuage dépendent elle de la coordonnée principale
Nuage::Nuage(std::mt19937 &rg)
    : Environnement{{util::alea(0, 1366, rg), util::alea(0, 200, rg)}},
      m_nuage1{m_coords, util::alea(30, 60, rg), util::alea(15, 35, rg), {253, 255, 255}},
      m_nuage2{{m_coords.getX() + m_nuage1.getRayonX(), m_coords.getY()},
          m_nuage1.getRayonX() * util::alea(0.6, 0.9, rg), m_nuage1.getRayonY() * util::alea(0.6, 0.9, rg),
          {255, 255, 255}},
      m_nuage3{{m_coords.getX() - m_nuage1.getRayonX(), m_coords.getY()},
          m_nuage1.getRayonX() * util::alea(0.3, 0.6, rg), m_nuage1.getRayonY() * util::alea(0.3, 0.6, rg),
          {250, 250, 250}} {}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Nuage
void Nuage::afficher() const {
    std::cout << "Nuage was created " << std::endl;
    m_coords.afficher();
    m_nuage1.afficher();
    m_nuage2.afficher();
    m_nuage3.afficher();
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Nuage::dessiner(Svgfile &svgout) {
    std::vector<Formes *> degrade;

    for (int i = 1; i < 25; ++i)
        degrade.push_back(new Ellipse{{m_coords}, m_nuage1.getRayonX() - (i / 2), m_nuage1.getRayonY() - (i / 2),
            {255 - i, 255 - i, 255 - i}});

    m_nuage1.dessiner(svgout);

    m_nuage2.dessiner(svgout);

    m_nuage3.dessiner(svgout);

    for (auto ptr: degrade)
        ptr->dessiner(svgout);
}

///fonction qui permet de deplacer l'objet
void Nuage::Translater(double coeff) {
    m_nuage1.Translater(coeff);
    m_nuage2.Translater(coeff);
    m_nuage3.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Nuage::TranslaterX(double consta) {
    m_nuage1.TranslaterX(consta);
    m_nuage2.TranslaterX(consta);
    m_nuage3.TranslaterX(consta);
}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Nuage::TranslaterY(double consta) {
    m_nuage1.TranslaterY(consta);
    m_nuage2.TranslaterY(consta);
    m_nuage3.TranslaterY(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Nuage::Zoom(double coeff) {
    m_nuage1.Zoom(coeff);
    m_nuage2.Zoom(coeff);
    m_nuage3.Zoom(coeff);
}

void Nuage::VarColFonc(Heure &heure) {

}

///Destructeur de Nuage
Nuage::~Nuage() {
    std::cout << "Nuage was destroyed" << std::endl;
    std::cout << std::endl;
}

