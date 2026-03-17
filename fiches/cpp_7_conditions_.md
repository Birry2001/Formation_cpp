Salut à tous ! Bienvenue pour cette septième séance. Aujourd'hui, on va donner de l'intelligence à nos programmes grâce aux **conditions**.

C'est ce qui va permettre à votre code de prendre des décisions : "Si l'utilisateur fait ceci, alors on fait cela". On va utiliser tout ce qu'on a appris sur les booléens et les opérateurs. Allez, on passe sur l'éditeur !

---

### 1. La structure de base : `if`, `else if` et `else` [[01:31](http://www.youtube.com/watch?v=TcqdKWAK894&t=91)]

Le `if` permet de tester une expression. Si elle est **vraie** (true), on exécute le code entre les accolades.

```cpp
#include <iostream>

int main() {
    int age {18};

    if (age >= 18) { // Condition principale [00:05:00]
        std::cout << "Vous etes majeur." << std::endl;
    } 
    else if (age > 12) { // Test intermédiaire si le premier a échoué [00:12:52]
        std::cout << "Vous etes ado." << std::endl;
    } 
    else { // Cas par défaut si rien n'a fonctionne [00:11:02]
        std::cout << "Vous etes un enfant." << std::endl;
    }

    return 0;
}

```

**À noter :**

* Le `else` n'a pas besoin de parenthèses car c'est le cas par défaut. [[16:28](http://www.youtube.com/watch?v=TcqdKWAK894&t=988)]
* Si vous n'avez qu'une seule instruction, les accolades `{}` ne sont pas obligatoires, mais je vous conseille de les mettre quand même pour la lisibilité ! [[03:41](http://www.youtube.com/watch?v=TcqdKWAK894&t=221)]

---

### 2. Combiner les tests [[06:03](http://www.youtube.com/watch?v=TcqdKWAK894&t=363)]

On peut tester plusieurs choses en même temps avec les opérateurs logiques.

```cpp
if (nombre < 500 && nombre >= 0) { // ET (les deux doivent être vrais) [00:06:19]
    std::cout << "Le nombre est dans la fourchette [0;500[." << std::endl;
}

if (nombre == 0 || nombre == 100) { // OU (au moins un des deux vrai) [00:07:32]
    std::cout << "Cas particulier." << std::endl;
}

```

---

### 3. Le `switch` : Pour les listes de choix [[18:48](http://www.youtube.com/watch?v=TcqdKWAK894&t=1128)]

Si vous avez beaucoup de valeurs précises à tester (comme un menu), le `switch` est plus propre que plein de `else if`.

```cpp
int choix {2};

switch (choix) {
    case 1:
        std::cout << "Option 1 choisie." << std::endl;
        break; // INDISPENSABLE pour sortir du switch ! [00:23:21]
    case 2:
        std::cout << "Option 2 choisie." << std::endl;
        break;
    default: // Comme le "else", pour tous les autres cas [00:23:50]
        std::cout << "Choix invalide." << std::endl;
        break;
}

```

---

### 4. La portée des variables (Scope) - TRÈS IMPORTANT [[25:17](http://www.youtube.com/watch?v=TcqdKWAK894&t=1517)]

Une variable créée **à l'intérieur** d'un bloc (entre `{ }`) n'existe plus en dehors de ce bloc.

```cpp
if (true) {
    int x {5}; // x est créé ici
} 
// std::cout << x; // ERREUR : x n'existe plus ici ! [00:28:59]

```

Par contre, un bloc "enfant" peut voir les variables de son "parent". [[27:44](http://www.youtube.com/watch?v=TcqdKWAK894&t=1664)]

---

### Fiche Mémoire Express 📝

| Mot-clé | Rôle | Note |
| --- | --- | --- |
| **`if`** | Teste une condition | Obligatoire pour démarrer un test. |
| **`else if`** | Tests supplémentaires | Autant que vous voulez. |
| **`else`** | Cas final | S'exécute si tout le reste a échoué. |
| **`switch`** | Sélecteur de cas | Plus propre pour les menus (entiers uniquement). |
| **`break`** | Sortie de secours | Utilisé dans le `switch` pour ne pas "couler" dans les autres cases. |
| **`default`** | Défaut du switch | Le `else` du `switch`. |

**Astuce moderne :** Depuis le C++17, vous pouvez initialiser une variable directement dans le `if` : `if (int x {10}; x > 5) { ... }`. C'est propre et ça limite la portée de `x`. [[17:14](http://www.youtube.com/watch?v=TcqdKWAK894&t=1034)]

Entraînez-vous à imbriquer des conditions et à bien gérer vos `break`. C'est comme ça qu'on construit la logique d'un logiciel.

Si vous avez des questions sur la portée ou les `switch`, n'hésitez pas dans les commentaires. Prochaine étape : on va apprendre à répéter des tâches avec les **boucles** ! À bientôt ! [[32:03](http://www.youtube.com/watch?v=TcqdKWAK894&t=1923)]