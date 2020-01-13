#include "sol.h"

///constructeur de Sol qui appel le constructeur de Environnment et Ellipse
///Couleur du Sol qui varie selon la graine et les intervalles Min et Max
Sol::Sol(std::mt19937 &rg)
    : Environnement{{util::alea(0, 1366, rg), util::alea(700, 786, rg)}},
      m_sol{m_coords, util::alea(500, 800, rg), util::alea(100, 200, rg),
          {util::alea(50, 154, rg), util::alea(50, 205, rg), util::alea(0, 50, rg)}} {}

///affiche les coordonnées du Sol
void Sol::afficher() const {
    std::cout << "Sol was created" << std::endl;
    m_sol.afficher();
}

///appel de la méthode dessiner de la classe Ellipse
void Sol::dessiner(Svgfile &svgout) {
    m_sol.dessiner(svgout);
}

///appel de la méthode Translater de la classe Ellipse
void Sol::Translater(double coeff) {
    m_sol.Translater(coeff);
}

///Appel de la méthode TranslaterX de la classe Ellipse
void Sol::TranslaterX(double consta) {
    m_sol.TranslaterX(consta);
}

///Appel de la méthode TranslaterY de la classe Ellipse
void Sol::TranslaterY(double consta) {
    m_sol.TranslaterY(consta);
}

///Appel de la méthode Zoom de la classe Ellipse
void Sol::Zoom(double coeff) {
    m_sol.Zoom(coeff);
}

void Sol::VarColFonc(Heure &heure) {
    ///variation de la couleur en fonction de l'heure
    ///De 7h a 12h
    if (heure.getHeure() >= 7 && heure.getHeure() < 12) {

    }
    ///De 12h a 17h
    if (heure.getHeure() >= 12 && heure.getHeure() < 17) {

    }
    ///De 17h a 20h
    if (heure.getHeure() >= 17 && heure.getHeure() < 20) {
    }
    ///De 20h a 23h     00h etant le milieu de la nuit
    if (heure.getHeure() >= 20 && heure.getHeure() <= 23) {
    }
    ///De 00h a 7h
    if (heure.getHeure() >= 0 && heure.getHeure() < 7) {
    }
}

Sol::~Sol() {

}
