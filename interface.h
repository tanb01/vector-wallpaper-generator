#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <conio.h>
#include "svg/svgfile.h"
#include "util/util.h"
#include "svg/couleur.h"
#include "objetscomplexes/plan.h"
#include "abstract/formes.h"
#include "abstract/environnement.h"
#include "primitives/cercle.h"
#include "primitives/rectangle.h"
#include "primitives/ellipse.h"
#include "primitives/triangle.h"
#include "interface/astre.h"
#include "interface/plantes.h"
#include "objetscomplexes/colline.h"
#include "objetscomplexes/sol.h"
#include "objetscomplexes/arbre.h"
#include "objetscomplexes/nuage.h"
#include "objetscomplexes/soleil.h"
#include "objetscomplexes/lune.h"
#include "objetscomplexes/etoile.h"
#include "objetscomplexes/ciel.h"
#include "objetscomplexes/fleur.h"
#include "objetscomplexes/herbe.h"
#include "objetscomplexes/montagne.h"
#include "objetscomplexes/champignon.h"
#include "heure.h"

///Menu de base
void afficherMenu();

///Procedure qui prend en parametre des plans et les dessines
void dessinerPlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant);

///Procedure qui prend en parametre des plans et ajoute des elements dedans
void CreerOeuvre(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant);

///Procedure qui prend en parametre des plans et ajoute des elements dedans
void GenererOeuvre(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant);

///Procedure qui prend en parametre des plans et affiche les objets qui compose le plan que l'utilisateur choisi
void afficherPlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant);

///Procedure qui prend en parametre des plans et detruit le plan choisi par l'utilisateur
void detruirePlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant);

void translaterPlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant);

///Procedure qui prend en parametre des plans, l'heure, la densite des objets, et un generateur aleatoire qui sera remplit par l'utilisateur
void parametres_generation(Heure &heure, int& densite_soleil, int& densite_lune, int& densite_etoile, int& densite_nuage,
                           int& densite_montagne, int& densite_sol, int& densite_colline, int& densite_sapin, int& densite_arbre,
                           int& densite_fleur, int& densite_herbe, int& densite_champ, int& taille_montagne_min, int& taille_montagne_max, std::mt19937& rg);

///Procedure qui prend en parametre l'heure et des objets de l'environnement pour ensuite changer leur couleur en focntion du temps
void Changer_Col_obj_Fonct_Heure(Heure &heure, std::vector<Environnement*>& things_arriere,
                                 std::vector<Environnement*>& things_semiarr,
                                 std::vector<Environnement*>& things_median,
                                 std::vector<Environnement*>& things_avant);

#endif // INTERFACE_H_INCLUDED

