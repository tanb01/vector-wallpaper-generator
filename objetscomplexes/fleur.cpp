#include "fleur.h"

///constructeur de Fleur qui appel le constructeur de Plantes, Rectangle et Cercle
///les coordonnées principales dépendent de l'intervalle ex: en Y Min=550 et Max=750 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonées de la tige et des pétales dépendent elle de la coordonnée principale
///la couleur des pétales est de base {255,174,201}
Fleur::Fleur(std::mt19937 &rg)
    : Plantes{{util::alea(0, 1366, rg), util::alea(550, 750, rg)}},
      m_tige{{m_coords.getX() - 2.5, m_coords.getY() - 30}, 5, 30, {120, 158, 137}},
      m_centre_fleur{{m_coords.getX(), m_coords.getY() - 30}, util::alea(5, 12, rg), {44, 16, 12}},
      m_petales1{{m_coords.getX() - m_centre_fleur.getRayon(), m_coords.getY() - 30}, m_centre_fleur.getRayon() - 1,
          {255, 174, 201}},
      m_petales2{{m_coords.getX(), m_coords.getY() + m_centre_fleur.getRayon() - 30}, m_centre_fleur.getRayon() - 1,
          {255, 174, 201}},
      m_petales3{{m_coords.getX() + m_centre_fleur.getRayon(), m_coords.getY() - 30}, m_centre_fleur.getRayon() - 1,
          {255, 174, 201}},
      m_petales4{{m_coords.getX(), m_coords.getY() - m_centre_fleur.getRayon() - 30}, m_centre_fleur.getRayon() - 1,
          {255, 174, 201}} {}

///affichage des coordonnées des fleurs et de sa hauteur et de son rayon
void Fleur::afficher() const {
    std::cout << "Fleur was created" << std::endl;
    m_coords.afficher();
    std::cout << "Hauteur: " << m_tige.getHauteur() << std::endl;
    std::cout << "Rayon: " << m_centre_fleur.getRayon() << std::endl << std::endl;
}

///appel aux méthodes dessiner des classes Cercle, rectangle
void Fleur::dessiner(Svgfile &svgout) {
    m_tige.dessiner(svgout);
    m_petales1.dessiner(svgout);
    m_petales2.dessiner(svgout);
    m_petales3.dessiner(svgout);
    m_petales4.dessiner(svgout);
    m_centre_fleur.dessiner(svgout);

}

///appel aux méthodes Translater des classes Cercle, Rectangle
void Fleur::Translater(double coeff) {
    m_tige.Translater(coeff);
    m_petales1.Translater(coeff);
    m_petales2.Translater(coeff);
    m_petales2.Translater(coeff);
    m_petales4.Translater(coeff);
    m_centre_fleur.Translater(coeff);
}

///appel aux méthodes TranslaterX des classes Cercle, Rectangle
void Fleur::TranslaterX(double consta) {
    m_tige.TranslaterX(consta);
    m_petales1.TranslaterX(consta);
    m_petales2.TranslaterX(consta);
    m_petales2.TranslaterX(consta);
    m_petales4.TranslaterX(consta);
    m_centre_fleur.TranslaterX(consta);
}

///appel aux méthodes TranslaterY des classes Cercle, Rectangle
void Fleur::TranslaterY(double consta) {
    m_tige.TranslaterY(consta);
    m_petales1.TranslaterY(consta);
    m_petales2.TranslaterY(consta);
    m_petales2.TranslaterY(consta);
    m_petales4.TranslaterY(consta);
    m_centre_fleur.TranslaterY(consta);
}

///appel aux méthodes Zoom des classes Cercle, Rectangle
void Fleur::Zoom(double coeff) {
    m_tige.Zoom(coeff);
    m_petales1.Zoom(coeff);
    m_petales2.Zoom(coeff);
    m_petales2.Zoom(coeff);
    m_petales4.Zoom(coeff);
    m_centre_fleur.Zoom(coeff);
}

void Fleur::VarColFonc(Heure &heure) {
    ///variation de la couleur en fonction de l'heure
    ///De 7h a 12h
    if (heure.getHeure() >= 7 && heure.getHeure() < 12) {

    }
    ///De 12h a 17h
    if (heure.getHeure() >= 12 && heure.getHeure() < 17) {
        //m_ciel.setCouleur({30+10*(heure.getHeure()-12)/(5) ,144+46*(heure.getHeure()-12)/(5), 255-0*(heure.getHeure()-12)/(5)});
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

///Destructeur de Fleur
Fleur::~Fleur() {
    std::cout << "Fleur was destroyed" << std::endl;
    std::cout << std::endl;
}

