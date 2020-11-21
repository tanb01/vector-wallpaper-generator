#include "ciel.h"

///Constructeur de Ciel qui appel le constructeur de Environnment et Rectangle
///Couleur du ciel bleu de base {30,144,255}
Ciel::Ciel(std::mt19937 &rg)
    : Environnement{{0, 0}}, m_ciel{{0, 0}, 1366, 768, {30, 144, 255}} {}

///Afichage des coordonées du ciel
void Ciel::afficher() const {
    std::cout << "Ciel was created" << std::endl;
    m_ciel.afficher();
}

///Appel de la fonction dessiner de la classe Cercle
void Ciel::dessiner(Svgfile &svgout) {
    m_ciel.dessiner(svgout);

///BONUS
    for (int i = 1; i < 10; ++i)
        svgout.addDisk(683, 393, 500 - (10 * i), makeRGB(m_ciel.getCouleur().getRouge() + 20,
                                                         m_ciel.getCouleur().getVert() + 36,
                                                         m_ciel.getCouleur().getBleu()), (i / 10.0));
}

///Appel a la fonction Translater de la classe Rectangle
void Ciel::Translater(double coeff) {
    m_ciel.Translater(coeff);
}

///Appel a la fonction TranslaterX de la classe Rectangle
void Ciel::TranslaterX(double consta) {
    m_ciel.TranslaterX(consta);
}

///Appel a la fonction TranslaterY de la classe Rectangle
void Ciel::TranslaterY(double consta) {
    m_ciel.TranslaterY(consta);
}

///Variation de la couleur en fonction de l'heure
void Ciel::VarColFonc(Heure &heure) {
    ///De 7h a 12h
    if (heure.getHeure() >= 7 && heure.getHeure() < 12)
        m_ciel.setCouleur({(254 - 224) * (heure.getHeure() - 7) / (5), 155 - 11 * (heure.getHeure() - 7) / (5),
                              70 + 185 * (heure.getHeure() - 7) / (5)});

    ///De 12h a 17h
    if (heure.getHeure() >= 12 && heure.getHeure() < 17)
        m_ciel.setCouleur({30 + 10 * (heure.getHeure() - 12) / (5), 144 + 46 * (heure.getHeure() - 12) / (5),
                              255 - 0 * (heure.getHeure() - 12) / (5)});

    ///De 17h a 20h
    if (heure.getHeure() >= 17 && heure.getHeure() < 20)
        m_ciel.setCouleur({40 + 214 * (heure.getHeure() - 17) / (3), 190 - 35 * (heure.getHeure() - 17) / (3),
                              255 - 185 * (heure.getHeure() - 17) / (3)});

    ///De 20h a 23h     00h etant le milieu de la nuit
    if (heure.getHeure() >= 20 && heure.getHeure() <= 23)
        m_ciel.setCouleur({254 - 202 * (heure.getHeure() - 20) / 4, 155 - 93 * (heure.getHeure() - 20) / 4,
                              70 + 163 * (heure.getHeure() - 20) / 4});
    ///De 00h a 7h
    if (heure.getHeure() >= 0 && heure.getHeure() < 7)
        m_ciel.setCouleur({52 + 202 * (heure.getHeure() - 0) / 5, 62 + 93 * (heure.getHeure() - 0) / 5,
                              233 - 163 * (heure.getHeure() - 0) / 5});
}

///Destructeur de Ciel
Ciel::~Ciel() {
    std::cout << "Ciel was destroyed" << std::endl;
    std::cout << std::endl;
}
