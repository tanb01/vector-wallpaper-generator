#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <random>
#include <string>
#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

namespace util
{

/// L'appel de cette fonction redirige les
/// données du fichier dont le nom est passé
/// en paramètre vers std::cin
/// On "simule" les frappes clavier ce qui
/// permet de tester sans avoir à retaper
/// à chaque fois les même données
/// temporisation : nombre de milliseconde entre chaque frappe clavier
/// couleur : colorisation (WINDOWS seulement https://ss64.com/nt/color.html
///                         préfixer par 0x, exemple 0x1a vert sur fond bleu)
void startAutoCin(std::string fileName, size_t temporisation=0, short couleur=0);

/// Cette fonction doit être appelée pour
/// terminer la saisie automatique et retrouver
/// un comportement normal (saisir au clavier)
void stopAutoCin();

/// Vide tampon clavier
void videCin();

/// Cette fonction retourne un entier aléatoire dans [min...max]
int alea(int min, int max);

/// Cette fonction retourne un réel aléatoire dans [min...max[
double alea(double min, double max);

/// Cette fonction retourne un entier aléatoire dans [min...max]
int alea(int min, int max, std::mt19937& randGen);

/// Cette fonction retourne un réel aléatoire dans [min...max[
double alea(double min, double max, std::mt19937& randGen);


/// Le code qui suit est spécifique aux plateformes Windows
/// et ne concerne ni macOS ni les Linux
#ifdef _WIN32
void accentsPourWindows();
#endif // _WIN32

}


#endif // UTIL_H_INCLUDED
