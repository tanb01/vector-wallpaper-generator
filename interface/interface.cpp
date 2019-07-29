#include "interface.h"

///Procedure pour afficher menu de base
void afficherMenu()
{
    std::cout<<"0. Quitter"<<std::endl;
    std::cout<<"1. Dessiner scene"<<std::endl;
    std::cout<<"2. Creer un paysage"<<std::endl;
    std::cout<<"3. Generer un paysage"<<std::endl;
    std::cout<<"4. Afficher un groupe d'objets"<<std::endl;
    std::cout<<"5. Detruire un groupe d'objets"<<std::endl;
}

///Procedure pour dessiner tout les plans
void dessinerPlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant)
{
    Svgfile svgout;
    Arriere.dessiner(svgout);
    SemiArr.dessiner(svgout);
    Median.dessiner(svgout);
    Avant.dessiner(svgout);
    //svgout.addGrid();
}

///Procedure pour afficher individuellement les elements de chaque plan
void afficherPlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant)
{
    char choix=10;
    do
    {
        std::cout<<"0. Retour"<<std::endl;
        std::cout<<"1. Afficher Arriere"<<std::endl;
        std::cout<<"2. Afficher Semi arriere"<<std::endl;
        std::cout<<"3. Afficher Median"<<std::endl;
        std::cout<<"4. Afficher Avant"<<std::endl<<std::endl;
        std::cout<<"Saisir votre action: ";
        do
        {
            choix = '9';
            choix = getch();
        }
        while (choix != '0' && choix != '1' && choix != '2' && choix != '3' && choix != '4');

        std::cout<<choix<<std::endl<<std::endl;

        switch(choix)
        {
        case '0':
            break;
        case '1':
        {
            Arriere.afficher();
            break;
        }
        case '2':
        {
            SemiArr.afficher();
            break;
        }
        case '3':
        {
            Median.afficher();
            break;
        }
        case '4':
        {
            Avant.afficher();
            break;
        }
        default :
            std::cout << "Choix Invalide" << std::endl << std::endl;
        }
    }
    while (choix!='0');
}

///Procedure pour detruire chaque plan au choix de l'utilisateur
void detruirePlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant)
{
    char choix=10;
    do
    {
        std::cout<<"0. Retour"<<std::endl;
        std::cout<<"1. Detruire Arriere"<<std::endl;
        std::cout<<"2. Detruire Semi arriere"<<std::endl;
        std::cout<<"3. Detruire Median"<<std::endl;
        std::cout<<"4. Detruire Avant"<<std::endl;
        std::cout<<"Saisir votre action: "<<std::endl<<std::endl;
        do
        {
            choix = '9';
            choix = getch();
        }
        while (choix != '0' && choix != '1' && choix != '2' && choix != '3' && choix != '4');

        std::cout<<choix<<std::endl;

        switch(choix)
        {
        case '0':
            break;
        case '1':
        {
            Arriere.viderEnvironnement();
            break;
        }
        case '2':
        {
            SemiArr.viderEnvironnement();
            break;
        }
        case '3':
        {
            Median.viderEnvironnement();
            break;
        }
        case '4':
        {
            Avant.viderEnvironnement();
            break;
        }
        default :
            std::cout << "Choix Invalide" << std::endl << std::endl;
        }
    }
    while (choix!='0');
}

///Procedure pour remplir les donnees de generation par l'utilisateur
void parametres_generation(Heure &heure, int& densite_soleil, int& densite_lune, int& densite_etoile, int& densite_nuage,
                           int& densite_montagne, int& densite_sol, int& densite_colline, int& densite_arbre,
                           int& densite_fleur, int& densite_herbe, int& densite_champ, int& taille_montagne_min, int& taille_montagne_max)
{
    heure.saisirHeure();

    do
    {
        std::cout<<"Densite d'arbres:";
        std::cin>>densite_arbre;
        std::cout<<std::endl;
    }
    while(densite_arbre<1);

    do
    {
        std::cout<<"Densite de champignons:";
        std::cin>>densite_champ;
        std::cout<<std::endl;
    }
    while(densite_champ<1);

    do
    {
        std::cout<<"Densite de montagnes:";
        std::cin>>densite_montagne;
        std::cout<<std::endl;
    }
    while(densite_montagne<1);

    std::cout<<"Taille minimum des Montagnes:";
    std::cin>>taille_montagne_min;
    std::cout<<std::endl;

    do
    {
        std::cout<<"Taille maximum des Montagnes:";
        std::cin>>taille_montagne_max;
        std::cout<<std::endl;
    }
    while(taille_montagne_max < taille_montagne_min);

    do
    {
        std::cout<<"Densite de collines:";
        std::cin>>densite_colline;
        std::cout<<std::endl;
    }
    while(densite_colline<1);

    do
    {
        std::cout<<"Densite de sol:";
        std::cin>>densite_sol;
        std::cout<<std::endl;
    }
    while(densite_sol<1);

    do
    {
        std::cout<<"Densite de lunes:";
        std::cin>>densite_lune;
        std::cout<<std::endl;
    }
    while(densite_lune<1);

    do
    {
        std::cout<<"Densite de soleils:";
        std::cin>>densite_soleil;
        std::cout<<std::endl;
    }
    while(densite_soleil<1);

    do
    {
        std::cout<<"Densite de l'herbe:";
        std::cin>>densite_herbe;
        std::cout<<std::endl;
    }
    while(densite_herbe<1);

    do
    {
        std::cout<<"Densite de fleurs:";
        std::cin>>densite_fleur;
        std::cout<<std::endl;
    }
    while(densite_fleur<1);

    do
    {
        std::cout<<"Densite de nuages:";
        std::cin>>densite_nuage;
        std::cout<<std::endl;
    }
    while(densite_nuage<1);

    do
    {
        std::cout<<"Densite d'etoiles:";
        std::cin>>densite_etoile;
        std::cout<<std::endl;
    }
    while(densite_etoile<1);
}

///Procedure pour chercher un objet et le faire varier la couleur en fonction du temps
void Changer_Col_obj_Fonct_Heure(Heure &heure, std::vector<Environnement*>& things_arriere,
                                 std::vector<Environnement*>& things_semiarr,
                                 std::vector<Environnement*>& things_median,
                                 std::vector<Environnement*>& things_avant)
{
    for(const auto& envptr: things_arriere)
    {
        ///est ce que j'ai un ciel
        Ciel* cielptr= dynamic_cast<Ciel*>(envptr);
        if(cielptr)
        {
            cielptr->VarColFonc(heure);
        }
    }
    for(const auto& envptr: things_arriere)
    {
        ///est ce que j'ai une Lune
        Lune* luneptr= dynamic_cast<Lune*>(envptr);
        if(luneptr)
        {
            luneptr->VarColFonc(heure);
        }
    }
}

///Procedure pour creer un paysage avec les parametres choisi par l'utilisateur
void CreerOeuvre(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant)
{
    int graine=17;

    Heure heure;

    int densite_soleil=1;
    int densite_lune=1;
    int densite_etoile=1;
    int densite_nuage=1;
    int densite_montagne=1;
    int densite_sol=1;
    int densite_colline=1;
    int densite_arbre=1;
    int densite_fleur=1;
    int densite_herbe=1;
    int densite_champ=1;

    ///A rajouter
    int taille_montagne_min=40;
    int taille_montagne_max=200;

    std::cout<<"Saisie de vos parametres:"<<std::endl<<std::endl;
    std::cout<< "Graine: ";
    std::cin>> graine;

    parametres_generation(heure, densite_soleil, densite_lune, densite_etoile, densite_nuage,
                          densite_montagne, densite_sol, densite_colline, densite_arbre,
                          densite_fleur, densite_herbe, densite_champ, taille_montagne_min, taille_montagne_max);

    std::mt19937 rg{graine};

    std::vector<Environnement*> things_arriere;
    std::vector<Environnement*> things_semiarr;
    std::vector<Environnement*> things_median;
    std::vector<Environnement*> things_avant;

    things_arriere.push_back(new Ciel(rg));

    if (heure.Nuit_ou_Jour())
    {
        things_arriere.push_back(new Soleil(rg));
    }
    else
    {
        things_arriere.push_back(new Lune(rg));

        for (int i=0; i<densite_etoile*10 ; ++i)
            things_arriere.push_back(new Etoile(rg));
    }

    for (auto i=0; i<densite_nuage*10; ++i)
    {
        Environnement* arptr=new Nuage(rg);
        things_semiarr.push_back(arptr);
    }

    for (auto i=0; i<densite_montagne*4; ++i)
    {
        Environnement* arptr=new Montagne(rg);
        things_semiarr.push_back(arptr);
    }

    for (auto i=0; i<densite_montagne*4; ++i)
    {
        Environnement* arptr=new Montagne(rg, taille_montagne_min, taille_montagne_max);
        things_semiarr.push_back(arptr);
    }

    for (auto i=0; i<densite_sol*7; ++i)
    {
        Environnement* arptr=new Sol(rg);
        things_median.push_back(arptr);
    }

    for (auto i=0; i<densite_colline*7; ++i)
    {
        Environnement* arptr=new Colline(rg);
        things_median.push_back(arptr);
    }

    for (auto i=0; i<densite_arbre*10; ++i)
    {
        Environnement* arptr=new Arbre(rg);
        things_avant.push_back(arptr);
    }

    for (auto i=0; i<densite_fleur*10; ++i)
    {
        Environnement* arptr=new Fleur(rg);
        things_avant.push_back(arptr);
    }

    for (auto i=0; i<densite_herbe*10; ++i)
    {
        Environnement* arptr=new Herbe(rg);
        things_avant.push_back(arptr);
    }

    for (auto i=0; i<densite_champ*10; ++i)
    {
        Environnement* arptr=new Champignon(rg);
        things_avant.push_back(arptr);
    }

///Avant de remplir on change la couleur
    Changer_Col_obj_Fonct_Heure(heure, things_arriere, things_semiarr, things_median, things_avant);

    Arriere.remplirEnvironnement(things_arriere);
    SemiArr.remplirEnvironnement(things_semiarr);
    Median.remplirEnvironnement(things_median);
    Avant.remplirEnvironnement(things_avant);

    Arriere.trier();
    SemiArr.trier();
    Median.trier();
    Avant.trier();
}

///Procedure pour generer pseudo aleatoirement un paysage a partir d'une graine saisi par l'utilisateur
void GenererOeuvre(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant)
{
    Arriere.viderEnvironnement();
    SemiArr.viderEnvironnement();
    Median.viderEnvironnement();
    Avant.viderEnvironnement();

    int graine=17;

    std::cout<<"Saisie de vos parametres:"<<std::endl<<std::endl;
    std::cout<< "Graine: ";
    std::cin>> graine;

    std::mt19937 rg{graine};

    Heure heure(rg);

    int densite_soleil=1;
    int densite_lune=1;
    int densite_etoile=util::alea(20, 30, rg);
    int densite_nuage=util::alea(7, 10, rg);
    int densite_montagne=util::alea(8, 10, rg);
    int densite_sol=util::alea(7, 10, rg);
    int densite_colline=util::alea(6, 10, rg);
    int densite_arbre=util::alea(5, 20, rg);
    int densite_fleur=util::alea(20, 40, rg);
    int densite_herbe=util::alea(1, 50, rg);
    int densite_champ=util::alea(20, 40, rg);


    std::vector<Environnement*> things_arriere;
    std::vector<Environnement*> things_semiarr;
    std::vector<Environnement*> things_median;
    std::vector<Environnement*> things_avant;

    things_arriere.push_back(new Ciel(rg));

    if (heure.Nuit_ou_Jour())
    {
        things_arriere.push_back(new Soleil(rg));
    }
    else
    {
        things_arriere.push_back(new Lune(rg));

        for (int i=0; i<densite_etoile; ++i)
            things_arriere.push_back(new Etoile(rg));
    }

    for (auto i=0; i<densite_nuage; ++i)
    {
        Environnement* arptr=new Nuage(rg);
        things_semiarr.push_back(arptr);
    }

    for (auto i=0; i<densite_montagne; ++i)
    {
        Environnement* arptr=new Montagne(rg);
        things_semiarr.push_back(arptr);
    }

    for (auto i=0; i<densite_sol; ++i)
    {
        Environnement* arptr=new Sol(rg);
        things_median.push_back(arptr);
    }

    for (auto i=0; i<densite_colline; ++i)
    {
        Environnement* arptr=new Colline(rg);
        things_median.push_back(arptr);
    }

    for (auto i=0; i<densite_arbre; ++i)
    {
        Environnement* arptr=new Arbre(rg);
        things_avant.push_back(arptr);
    }

    for (auto i=0; i<densite_fleur; ++i)
    {
        Environnement* arptr=new Fleur(rg);
        things_avant.push_back(arptr);
    }

    for (auto i=0; i<densite_herbe; ++i)
    {
        Environnement* arptr=new Herbe(rg);
        things_avant.push_back(arptr);
    }

    for (auto i=0; i<densite_champ; ++i)
    {
        Environnement* arptr=new Champignon(rg);
        things_avant.push_back(arptr);
    }

    ///Avant de remplir on change la couleur
    Changer_Col_obj_Fonct_Heure(heure, things_arriere, things_semiarr, things_median, things_avant);

    Arriere.remplirEnvironnement(things_arriere);
    SemiArr.remplirEnvironnement(things_semiarr);
    Median.remplirEnvironnement(things_median);
    Avant.remplirEnvironnement(things_avant);

    Arriere.trier();
    SemiArr.trier();
    Median.trier();
    Avant.trier();
}

void translaterPlan(Plan& Arriere, Plan& SemiArr, Plan& Median, Plan& Avant)
{

}
