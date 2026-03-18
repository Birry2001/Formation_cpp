#include <iostream>

#include "../include/classes.hpp"

#include <string>

CompteBancaire::CompteBancaire(std::string proprietaire, double solde): propriétaire_(proprietaire), solde_(solde)
{

}

void CompteBancaire::affichesolde()
{
    std::cout<<"Voici le solde:"<< this->solde_<<std::endl;
}

void CompteBancaire::deposer( double montant)
{
    this->solde_ += montant;
}

void CompteBancaire::retirer( double montant)
{
    this->solde_ -= montant;
}

std::string CompteBancaire::getProprietaire()
{
    return this->propriétaire_;
}
