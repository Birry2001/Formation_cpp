Salut à tous ! Bienvenue pour cette quatrième séance. Aujourd'hui, on s'attaque à un morceau énorme, le pilier de la programmation : **les variables**.

Sans elles, impossible de mémoriser quoi que ce soit pendant que votre programme tourne. On va voir comment déclarer tout ça, comment choisir les bons types et surtout comment les manipuler proprement. Allez, on passe sur l'éditeur !

---

### 1. Qu'est-ce qu'une variable ? [[00:22](http://www.youtube.com/watch?v=3exIzj5MYzU&t=22)]

C'est une zone dans la mémoire de votre ordinateur où l'on va stocker une information.

* **Pendant l'exécution** : la donnée est mémorisée.
* **À la fin du programme** : la mémoire est libérée, tout est détruit. [[01:13](http://www.youtube.com/watch?v=3exIzj5MYzU&t=73)]

Pour créer une variable, il nous faut trois choses : un **type**, un **nom** (identificateur) et une **valeur**.

---

### 2. Le Nommage : Soyez explicites ! [[03:00](http://www.youtube.com/watch?v=3exIzj5MYzU&t=180)]

Ne donnez pas des noms au hasard. Le but, c'est que votre code soit "auto-documenté".

* **Interdit** : Commencer par un chiffre, utiliser des espaces ou des mots réservés du langage (comme `return` ou `int`). [[03:38](http://www.youtube.com/watch?v=3exIzj5MYzU&t=218)]
* **Styles autorisés** : `mon_message` (snake_case) ou `monMessage` (camelCase). L'important, c'est d'être cohérent ! [[05:08](http://www.youtube.com/watch?v=3exIzj5MYzU&t=308)]

---

### 3. Les Types Fondamentaux [[06:31](http://www.youtube.com/watch?v=3exIzj5MYzU&t=391)]

Voici les types que vous allez croiser 99% du temps :

```cpp
bool  isReady {true};    // Booléen : vrai (true) ou faux (false) [00:07:50]
int   age {25};          // Entier (ex: 1, 42, -5) [00:08:50]
float prix {19.99f};     // Nombre à virgule (flottant), simple précision [00:09:27]
double pi {3.14159};     // Nombre à virgule, double précision (plus précis) [00:09:27]
char  lettre {'A'};      // Un seul caractère (entre simples quotes) [00:23:50]

```

**Astuce d'expert :** Pour les grands nombres, utilisez l'apostrophe comme séparateur de milliers pour mieux lire votre code : `int population {67'000'000};` [[22:38](http://www.youtube.com/watch?v=3exIzj5MYzU&t=1358)]

---

### 4. Déclaration, Initialisation et Modification [[12:12](http://www.youtube.com/watch?v=3exIzj5MYzU&t=732)]

En C++ moderne, on préfère utiliser les accolades `{}` pour initialiser nos variables.

```cpp
#include <iostream>
#include <string> // Obligatoire pour utiliser les chaînes de caractères [00:25:03]

int main() {
    int score {100}; // Déclaration + Initialisation
    
    std::cout << "Score actuel : " << score << std::endl;

    score = 150; // Modification de la valeur [00:27:13]
    std::cout << "Nouveau score : " << score << std::endl;

    // Constante : impossible de changer la valeur après ! [00:31:13]
    const int ID_JOUEUR {4555}; 
    
    // ID_JOUEUR = 0; // ERREUR DE COMPILATION ! [00:32:24]

    return 0;
}

```

---

### 5. Le mot-clé `auto` : Laissez le compilateur travailler [[33:43](http://www.youtube.com/watch?v=3exIzj5MYzU&t=2023)]

Si la valeur est évidente, vous pouvez laisser le C++ deviner le type tout seul. C'est très pratique et ça évite de se tromper entre un `int` et un `long`.

```cpp
auto ratio {1.5f}; // Le compilateur comprend que c'est un float
auto message {std::string("Hello")}; // Déduit std::string [00:37:05]

```

---

### Fiche Mémoire Express 📝

| Concept | Syntaxe / Exemple | Note |
| --- | --- | --- |
| **Variable** | `int nombre {10};` | Valeur qui peut changer. |
| **Constante** | `const int MAX {100};` | Sécurité : valeur verrouillée. |
| **Affectation** | `variable = nouvelle_valeur;` | On utilise le signe `=`. |
| **Chaîne** | `std::string texte {"Bonjour"};` | Nécessite `#include <string>`. |
| **Auto** | `auto x {5};` | Déduction automatique du type. |

**Votre mission :** Entraînez-vous à créer des variables de chaque type, affichez-les, modifiez-les et essayez de changer une constante pour voir le compilateur vous gronder. C'est en faisant des erreurs qu'on apprend ! [[40:43](http://www.youtube.com/watch?v=3exIzj5MYzU&t=2443)]

Si vous avez un doute sur un type ou une syntaxe, direction les commentaires. Prochaine étape : on va faire des maths avec nos variables ! À bientôt ! [[41:31](http://www.youtube.com/watch?v=3exIzj5MYzU&t=2491)]