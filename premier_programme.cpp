#include <iostream>
#include <string>
#include <typeinfo>
#include <string>
int main() {
    
    //std::cout<<"Hello world"<<std::endl; 
    //std::string Hello_world{"Hello world!"};
    //std::cout<<Hello_world<<std::endl;

    auto nous = false;
    decltype(nous) b;
    b = false;  
    std::cout<<typeid(nous).name()<<std::endl;
    std::string votre_nom;
    std::cout<<"entrez votre nome"<<std::endl;
    std::cin>>votre_nom;


    return 0;
}
