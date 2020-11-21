#include "couleur.h"
#include "../svg/svgfile.h"
#include "../util/util.h"
#include <iostream>

Couleur::Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : m_rouge{rouge}, m_vert{vert}, m_bleu{bleu} {}

Couleur::Couleur()
    : Couleur(0, 0, 0) // Délégation de constructeur
{}

void Couleur::afficher() const {
    std::cout << "(" << (int) m_rouge << ", " << (int) m_vert << ", " << (int) m_bleu << ")" << std::endl;
}

uint8_t saisirCanal() {
    int val;
    std::cin >> val;
    while (val < 0 || val > 255) {
        std::cout << "Mauvaise valeur couleur, recommencer : ";
        util::videCin();
        std::cin >> val;
    }

    return (uint8_t) val;
}

void Couleur::saisir() {
    std::cout << "Veuillez saisir rouge vert et bleu SVP : ";
    m_rouge = saisirCanal();
    m_vert = saisirCanal();
    m_bleu = saisirCanal();
}

uint8_t muterCanal(uint8_t v, double amplitude) {
    int val = v;

    val += util::alea(-amplitude, amplitude);

    if (val < 0)
        val = 0;

    if (val > 255)
        val = 255;

    return (uint8_t) val;
}

void Couleur::muter(double amplitude) {
    m_rouge = muterCanal(m_rouge, amplitude);
    m_vert = muterCanal(m_vert, amplitude);
    m_bleu = muterCanal(m_bleu, amplitude);
}

Couleur::operator std::string() const {
    return makeRGB(m_rouge, m_vert, m_bleu);
}

void Couleur::setRouge(int rouge) {
    m_rouge = rouge;
}

void Couleur::setVert(int vert) {
    m_vert = vert;
}

void Couleur::setBleu(int bleu) {
    m_bleu = bleu;
}

int Couleur::getRouge() const {
    return m_rouge;
}

int Couleur::getVert() const {
    return m_vert;
}

int Couleur::getBleu() const {
    return m_bleu;
}

