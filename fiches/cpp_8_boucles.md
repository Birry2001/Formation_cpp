Salut à tous ! Bienvenue pour cette huitième séance. Comme promis, après les conditions, on s'attaque aux **boucles**.

C'est l'outil qui va vous permettre de répéter des instructions sans avoir à réécrire dix fois la même ligne de code. On va voir comment faire des itérations proprement et comment éviter de faire planter son PC avec des boucles infinies ! Allez, on passe sur le code !

---

### 1. La boucle `while` (Tant que) [[02:54](http://www.youtube.com/watch?v=blot7YV0MH4&t=174)]

C'est la boucle la plus simple : tant que l'expression entre parenthèses est **vraie**, on recommence le bloc de code.

```cpp
#include <iostream>

int main() {
    int i {0}; // Notre compteur (souvent appelé 'i' pour iterator) [00:02:37]

    while (i < 10) { // Test avant l'exécution [00:04:14]
        std::cout << "Itération numero : " << i << std::endl;
        i++; // SUPER IMPORTANT : on incrémente pour ne pas boucler à l'infini ! [00:05:03]
    }

    return 0;
}

```

**Le piège :** Si vous oubliez le `i++`, `i` restera à 0, la condition `0 < 10` sera toujours vraie, et votre programme ne s'arrêtera jamais. C'est la fameuse **boucle infinie**. [[04:33](http://www.youtube.com/watch?v=blot7YV0MH4&t=273)]

---

### 2. La boucle `do... while` (Faire... tant que) [[08:43](http://www.youtube.com/watch?v=blot7YV0MH4&t=523)]

À l'inverse du `while` classique, ici on exécute le code **au moins une fois** avant de faire le premier test.

```cpp
int i {15};

do {
    std::cout << "Ceci s'affichera au moins une fois." << std::endl;
} while (i < 10); // Le test est fait à la fin [00:09:05]

```

---

### 3. La boucle `for` (Pour) [[13:43](http://www.youtube.com/watch?v=blot7YV0MH4&t=823)]

C'est la version condensée et préférée quand on sait combien de fois on veut boucler. Tout est réuni sur une seule ligne.

```cpp
// (Initialisation ; Condition ; Incrémentation) [00:13:58]
for (int i {0}; i < 10; ++i) {
    std::cout << "Tour numero " << i << std::endl;
}

```

L'avantage ? On ne peut pas oublier l'incrémentation, elle est déjà dans la structure ! [[15:22](http://www.youtube.com/watch?v=blot7YV0MH4&t=922)]

---

### 4. `break` et `continue` [[10:05](http://www.youtube.com/watch?v=blot7YV0MH4&t=605)]

* **`break`** : On casse tout et on sort immédiatement de la boucle. [[10:07](http://www.youtube.com/watch?v=blot7YV0MH4&t=607)]
* **`continue`** : On ignore la fin du tour actuel et on passe direct à l'itération suivante. [[10:33](http://www.youtube.com/watch?v=blot7YV0MH4&t=633)]

---

### 5. Bonus : La boucle `for` sur une collection (Range-based) [[16:56](http://www.youtube.com/watch?v=blot7YV0MH4&t=1016)]

Depuis le C++ moderne, on peut parcourir facilement des éléments séquentiels comme une chaîne de caractères (string).

```cpp
#include <string>

std::string phrase {"Bonjour"};

// Pour chaque lettre de la phrase... [00:18:04]
for (auto lettre : phrase) {
    std::cout << lettre << std::endl; // Affiche chaque lettre une par une
}

```

---

### Fiche Mémoire Express 📝

| Boucle | Usage | Particularité |
| --- | --- | --- |
| **`while`** | Répétition indéfinie | Test **avant** : peut ne jamais s'exécuter. |
| **`do... while`** | Répétition indéfinie | Test **après** : s'exécute au moins une fois. |
| **`for`** | Répétition définie | Compact : idéal pour les compteurs. |
| **`for (auto x : col)`** | Parcours | Idéal pour lire chaque élément d'une liste/string. |

**Votre mission :** Essayez de créer un petit compteur qui s'arrête prématurément avec un `break` si la valeur atteint 5. C'est en manipulant ces blocs qu'on comprend la portée des variables. [[20:43](http://www.youtube.com/watch?v=blot7YV0MH4&t=1243)]

Des questions sur les itérations ou les boucles infinies ? Lâchez-vous dans les commentaires. La prochaine fois, on verra peut-être comment organiser tout ça avec les **fonctions**. À bientôt ! [[21:23](http://www.youtube.com/watch?v=blot7YV0MH4&t=1283)]