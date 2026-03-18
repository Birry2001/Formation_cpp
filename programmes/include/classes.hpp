#ifndef __CLASSES__
#define __CLASSES__
#include <string>

class CompteBancaire 
{

    public:

    // méthodes
    CompteBancaire() = default;
    CompteBancaire(std::string proprietaire, double solde );

    void affichesolde();
    void deposer(double montant);
    void retirer(double montant);
    std::string getProprietaire();

    //attributs

    std::string propriétaire_  = "vous";
    double solde_ = 50;



    private:
};






#endif