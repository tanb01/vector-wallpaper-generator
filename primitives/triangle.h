#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "../abstract/formes.h"
#include <vector>

/// D�claration d'un type "Triangle" qui h�rite de la classe "Formes"
class Triangle : public Formes {
  ///Methodes : d�claration
 public:
  Triangle(Coords sommetun, Coords sommetdeux, Coords sommettrois, Couleur couleur);

  Triangle(std::vector<Coords> sommets, Couleur couleur);

  virtual void afficher() const;
  virtual void dessiner(Svgfile &svgout);

  std::vector<Coords> getSommets() const;

  void setSommets(std::vector<Coords> sommets);

  virtual void Zoom(double coeff);

  ~Triangle();
  /// Attributs : d�claration
 private:
  std::vector<Coords> m_sommets;
  ///on cr�er un vector de sommets car notre triangle
  ///est d�fini en fonction de ces trois sommets
};

#endif // TRIANGLE_H_INCLUDED
