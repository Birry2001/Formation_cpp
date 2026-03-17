#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string name{""};
    int age{0};
    std::cout << "Bonjour, ecivez votre nom" << std::endl;
    std::cin >> name;
    std::cout << "Bonjour, ecivez votre age" << std::endl;
    std::cin >> age;

    std::ofstream file("profil.txt");
    if (file.is_open()) {
        file << "Prénom : " << name << std::endl;
        file << "Age : " << age << std::endl;
        file.close();
    }
    else {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }

    std::ifstream file_("profil.txt");

    if (file_.is_open()) {
        std::string line;
        while (std::getline(file_, line)) {
            std::cout << line << std::endl;
        }
        file_.close();
    }
    else {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }

    std::ofstream number("nombres.bin", std::ios::binary);
    if (number.is_open()) {
        int tableau[5] = {10, 20, 30, 40, 50};
        number.write(reinterpret_cast<char*>(tableau), sizeof(tableau));    
        number.close();
    }
    else {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    std::ifstream number_("nombres.bin", std::ios::binary);
    if (number_.is_open()) {
        int tableau[5] = {0};
        number_.read(reinterpret_cast<char*>(tableau), sizeof(tableau));
        number_.close();
        for (int i = 0; i < 5; i++) {
            std::cout << tableau[i] << std::endl;
        }
        number_.close();
        
    }
    else {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }

    return 0;
}
