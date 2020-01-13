#include "soleil.h"

///Constructeur de Soleil qui appel le constructeur de Astre et de Cercle
///les coordonnées principales dépendent de l'intervalle Min=50 et Max=250 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonées du soleil dépendent elle de la coordonnée principale
Soleil::Soleil(std::mt19937 &rg)
    : Astre{{util::alea(0, 1366, rg), util::alea(50, 250, rg)}},
      m_soleil{m_coords, util::alea(60, 110, rg), {255, 215, 0}} {}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Soleil qui sont son rayon et les coordonnées de son centre
void Soleil::afficher() const {
    std::cout << "Soleil was created " << std::endl;
    m_coords.afficher();
    std::cout << "Rayon: " << m_soleil.getRayon() << std::endl << std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Soleil::dessiner(Svgfile &svgout) {
    m_soleil.dessiner(svgout);

///Apres avoir dessiner le soleil dans le svg.file on rajoute des effets de brillance et de gradation
    for (int i = 1; i < 10; ++i)
        svgout.addDisk(m_coords.getX(),
                       m_coords.getY(),
                       m_soleil.getRayon() + i * 1.5,
                       makeRGB(255, 215 + 10 * i, i * 10),
                       0.1 + (i / 10));//{255, 115+(i/2), 0}});

    for (int i = 1; i < 10; ++i)
        svgout.addDisk(m_coords.getX(),
                       m_coords.getY(),
                       m_soleil.getRayon() + 7 - i,
                       makeRGB(255, 215, 0),
                       0.1 + (i / 10));//{255, 115+(i/2), 0}});
}

///fonction qui permet de deplacer l'objet
void Soleil::Translater(double coeff) {
    m_soleil.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Soleil::TranslaterX(double consta) {
    m_soleil.TranslaterX(consta);

}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Soleil::TranslaterY(double consta) {
    m_soleil.TranslaterY(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Soleil::Zoom(double coeff) {
    m_soleil.Zoom(coeff);
}

void Soleil::VarColFonc(Heure &heure) {

}

///Destructeur de Soleil
Soleil::~Soleil() {
    std::cout << "Soleil was destroyed" << std::endl;
    std::cout << std::endl;
}

