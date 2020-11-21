///Programmeurs: KARDACHE Noor, TAN Benjamin, ZHANG Simon

///Bibliotheques qu'on inclut
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "./interface/interface.h"

///Menu permettant l'utilisateur de:
///Dessiner un paysage, Creer un paysage,
///Afficher les elements des plans du paysage
///Et d'en detruire des plans
int main()
{
    srand(time(NULL));

    Plan Arriere;
    Plan SemiArr;
    Plan Median;
    Plan Avant;

    char choix =10;

    do
    {
        afficherMenu();

        std::cout<<"Saisir votre action: ";

        do
        {
            choix = '9';
            choix = getch();
        }
        while (choix != '0' && choix != '1' && choix != '2' && choix != '3' && choix != '4' && choix != '5');

        std::cout<<choix<<std::endl<<std::endl;

        switch(choix)
        {
        case '0':
            break;
        case '1':
        {
            dessinerPlan(Arriere, SemiArr, Median, Avant);
            break;
        }
        case '2':
        {
            CreerOeuvre(Arriere, SemiArr, Median, Avant);
            break;
        }
        case '3':
        {
            GenererOeuvre(Arriere, SemiArr, Median, Avant);
            break;
        }
        case '4':
        {
            afficherPlan(Arriere, SemiArr, Median, Avant);
            break;
        }
        case '5':
        {
            detruirePlan(Arriere, SemiArr, Median, Avant);
            break;
        }
                default :
            std::cout << "Choix Invalide" << std::endl << std::endl;
        }
    }
    while (choix!='0');

    return 0;
}
