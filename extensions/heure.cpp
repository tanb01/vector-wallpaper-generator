#include "heure.h"

///constructeur de Heure
///par défaut est à 12h00
Heure::Heure()
    :  m_heure{12}, m_minute{0}
{}

Heure::Heure(std::mt19937& rg)
    : m_heure{util::alea(0, 24, rg)}, m_minute{util::alea(0, 24, rg)}
{}

Heure::~Heure()
{

}

void Heure::saisirHeure()
{
    unsigned int heure=13;
    unsigned int minute=0;
    ///Demande de l'heure a l'utilisateur
    std::cout<< "Saisir l'heure digitale:"<<std::endl;


    std::cout<< "Heure:";
    ///Blindage
    do
    {
        std::cin>>heure;
        if(heure<24&&heure>=0)
            m_heure=heure;
        else
            std::cout<<" Heure non valable "<<std::endl;
    }
    while(heure>=24||heure<0);


    std::cout<< "Minutes:";
    ///Blindage
    do
    {
        std::cin>>minute;
        if(minute<60&&minute>=0)
            m_minute=minute;
        else
            std::cout<<" Heure non valable "<<std::endl;
    }
    while(minute>=60||minute<0);
}

///Accesseur de l'heure
unsigned int Heure::getHeure()
{
    return m_heure;
}

///Accesseur des Minutes
unsigned int Heure::getMinutes()
{
    return m_minute;
}

bool Heure::Nuit_ou_Jour()
{
    /// De base c'est le jour
    ///if l'heure est située entre 7 et 19h il s'agit du jour
    if(m_heure>=7&&m_heure<=19)
        return true;
    else
        return false;
}
