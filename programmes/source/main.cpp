#include <iostream>
#include "../include/math.hpp"
#include "../include/texte.hpp"

int main()
{
    std::cout <<"Hello WORLD"<< std::endl;
    //float prix {19.99f}; 
    char yo = 'o';

    struct Pluriel {
        double somme;
        std::string nombre ;
        bool choix;

    };

    using plu = struct Pluriel;

    plu Premier {};
    Premier.somme = 55;
    Premier.nombre = "yeeee";
    Premier.choix = false ;

    std::string liste[3] = {"somme", "nombre", "choix"};

    std::cout<<Premier.somme<<std::endl;

    if (yo=='o') {
        std::cout<<"KYS"<<std::endl;
    }
    Math::addition(2,4);
    Math::multiplication(3,6);
    Texte::bonjour();
    Texte::addition();
    return 0;

}
