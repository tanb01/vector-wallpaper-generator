#include "triangle.h"

/// Constructeur qui prend en paramêtres quatre variables (trois sommets et une couleur)
Triangle::Triangle(Coords sommetun, Coords sommetdeux, Coords sommettrois, Couleur couleur)
: Formes{(0.5)*(sommetun + sommetdeux + sommettrois), couleur}, m_sommets{sommetun, sommetdeux, sommettrois}
{}

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Triangle qui sont ses trois sommets et sa couleur
void Triangle::afficher() const
{
    m_coords.afficher();
    std::cout << "Sommets: " << std::endl;
    for (auto ptrsom : m_sommets)
    {
        ptrsom.afficher();
    }
    std::cout << "Couleur: " << (std::string)m_couleur << std::endl<< std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Triangle::dessiner(Svgfile& svgout)
{
    svgout.addPolygon(m_sommets, m_couleur);
}

/// Fonction qui cherche et retourne le vector de sommets de la classe Triangle
std::vector<Coords> Triangle::getSommets() const
{
    return m_sommets;
}

/// Fonction qui donne une valeur aux variables de la classe Triangle
void Triangle::setSommets(std::vector<Coords> sommets)
{
    m_sommets = sommets;
}

/// Fonction qui permet de modifier la taille du
///Triangle en modifiant les coordonnées de ses sommets
void Triangle::Zoom(double coeff)
{
    m_sommets[0]=(coeff*(m_sommets[0]-m_coords)+m_coords);
    m_sommets[1]=(coeff*(m_sommets[1]-m_coords)+m_coords);
    m_sommets[2]=(coeff*(m_sommets[2]-m_coords)+m_coords);
}

Triangle::~Triangle()
{

}
