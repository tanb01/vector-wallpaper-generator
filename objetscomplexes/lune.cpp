#include "lune.h"

///Constructeur de Lune qui appel le constructeur de Astre et de Cercle
///les coordonnées principales dépendent de l'intervalle Min=50 et Max=250 ici définit par la graine et la fonction util::alea du fichier util.h
///les coordonées du Lune et du croissant dépendent elle de la coordonnée principale
Lune::Lune(std::mt19937& rg)
    : Astre{{util::alea(0, 1366, rg), util::alea(50, 250, rg)}},
m_lune{m_coords, util::alea(40, 70, rg),  {240, 248, 255}},
m_croissant{{m_coords.getX()+((m_lune.getRayon())/2.5),m_coords.getY()},m_lune.getRayon()/1.3, {30, 144, 255}}
{}//NUIT//{0, 0, 128}}//    25, 25, 112

/// la fonction d'affichage, qui permet d'afficher les valeurs
///des parametres de Lune qui sont son rayon et les coordonnées de son centre
void Lune::afficher() const
{
    std::cout << "Lune was created "<< std::endl;
    m_coords.afficher();
    std::cout << "Rayon: " << m_lune.getRayon() << std::endl<< std::endl;
}

/// la fonction dessiner, qui permet de dessiner les objets dans le svg.file
void Lune::dessiner(Svgfile& svgout)
{
    std::vector<Formes*> degrade;

    m_lune.dessiner(svgout);

///Apres avoir dessiner la Lune dans le svg.file on rajoute des effets de gradation
    for (int i=1; i<230; ++i)
        degrade.push_back(new Cercle{{m_coords}, m_lune.getRayon()-(i/2), {240-i, 248-i, 255-i}});//{255, 115+(i/2), 0}});

    for (auto ptr: degrade)
        ptr->dessiner(svgout);

///On affiche le second cercle afin de créer le croissant de lune
    m_croissant.dessiner(svgout);
}

///fonction qui permet de deplacer l'objet
void Lune::Translater(double coeff)
{
    m_lune.Translater(coeff);
    m_croissant.Translater(coeff);
}

///fonction qui permet de deplacer l'objet sur l'axe des X
void Lune::TranslaterX(double consta)
{
    m_lune.TranslaterX(consta);
    m_croissant.Translater(consta);
}

///fonction qui permet de deplacer l'objet sur l'axe des Y
void Lune::TranslaterY(double consta)
{
    m_lune.TranslaterY(consta);
    m_croissant.Translater(consta);
}

///fonction qui permet de modifier la taille de l'objet
void Lune::Zoom(double coeff)
{
    m_lune.Zoom(coeff);
    m_croissant.Zoom(2*coeff);
}

void Lune::VarColFonc(Heure& heure)
{
    ///De 7h a 12h
    if(heure.getHeure()>=7&&heure.getHeure()<12)
        m_croissant.setCouleur({254-224*(heure.getHeure()-7)/(5),155-11*(heure.getHeure()-7)/(5), 70+185*(heure.getHeure()-7)/(5)});

    ///De 12h a 17h
    if(heure.getHeure()>=12&&heure.getHeure()<17)
        m_croissant.setCouleur({30+10*(heure.getHeure()-12)/(5),144+46*(heure.getHeure()-12)/(5), 255-0*(heure.getHeure()-12)/(5)});

    ///De 17h a 20h
    if(heure.getHeure()>=17&&heure.getHeure()<20)
        m_croissant.setCouleur({40+214*(heure.getHeure()-17)/(3), 190-35*(heure.getHeure()-17)/(3), 255-185*(heure.getHeure()-17)/(3)});

    ///De 20h a 23h     00h etant le milieu de la nuit
    if(heure.getHeure()>=20&&heure.getHeure()<=23)
        m_croissant.setCouleur({254-202*(heure.getHeure()-20)/4, 155-93*(heure.getHeure()-20)/4, 70+163*(heure.getHeure()-20)/4});
    ///De 00h a 7h
    if(heure.getHeure()>=0&&heure.getHeure()<7)
        m_croissant.setCouleur({52+202*(heure.getHeure()-0)/5, 62+93*(heure.getHeure()-0)/5, 233-163*(heure.getHeure()-0)/5});
}


///Destructeur de Lune
Lune::~Lune()
{
    std::cout << "Lune was destroyed" << std::endl;
    std::cout <<std::endl;
}

