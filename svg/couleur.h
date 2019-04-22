#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <string>
#include <cstdint>

class Couleur
{
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();
        void muter(double amplitude);

        operator std::string() const;
        ///Ajoute par Simon
        int getRouge() const;
        int getVert() const;
        int getBleu() const;

        void setRouge(int rouge);
        void setVert(int vert);
        void setBleu(int bleu);

    private :
        // uint8_t �quivalent � unsigned char :
        // unsigned 8 bits (8 bits non sign�)
        uint8_t m_rouge, m_vert, m_bleu;
};

#endif // COULEUR_H_INCLUDED
