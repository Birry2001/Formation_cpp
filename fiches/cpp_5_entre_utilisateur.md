Salut à tous ! Content de vous retrouver pour cette séance 5. On a vu comment mémoriser des données avec les variables, maintenant on va apprendre à laisser l'utilisateur interagir avec nos programmes. On va voir comment récupérer ce qu'il tape au clavier. Allez, on passe sur le code !

---

### 1. La saisie de base avec `std::cin` [[00:45](http://www.youtube.com/watch?v=tkCCUzIErNU&t=45)]

Pour l'affichage on utilisait `std::cout` (flux de sortie), pour la lecture on utilise **`std::cin`** (flux d'entrée).

```cpp
#include <iostream>

int main() {
    int nombre {0};
    std::cout << "Tapez un nombre entier : ";
    
    // On utilise l'opérateur >> pour diriger le flux vers la variable [00:01:31]
    std::cin >> nombre; 
    
    std::cout << "Vous avez saisi : " << nombre << std::endl;
    return 0;
}

```

**Attention :** `std::cin` s'arrête au premier espace blanc (espace, tabulation ou retour à la ligne) rencontré. Si vous tapez "12 45", il ne lira que "12". [[02:30](http://www.youtube.com/watch?v=tkCCUzIErNU&t=150)]

---

### 2. Lire une ligne complète avec `std::getline` [[09:01](http://www.youtube.com/watch?v=tkCCUzIErNU&t=541)]

Si vous voulez récupérer une chaîne de caractères avec des espaces (comme un nom complet), `std::cin >>` ne suffit pas. On utilise alors **`std::getline`**.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string nomComplet;
    std::cout << "Tapez votre nom complet : ";
    
    // Lit toute la ligne jusqu'au retour à la ligne (\n) [00:10:16]
    std::getline(std::cin, nomComplet);
    
    std::cout << "Salut " << nomComplet << " !" << std::endl;
    return 0;
}

```

---

### 3. Le piège du mélange `cin` et `getline` [[12:20](http://www.youtube.com/watch?v=tkCCUzIErNU&t=740)]

C'est l'erreur classique du débutant. Quand vous faites `std::cin >> nombre`, le caractère "Entrée" (`\n`) reste dans le tampon. Si vous faites un `getline` juste après, il va lire ce "Entrée" vide et ne pas vous laisser taper votre texte. [[14:15](http://www.youtube.com/watch?v=tkCCUzIErNU&t=855)]

**La solution :** Nettoyer le tampon entre les deux.

```cpp
int age;
std::string nom;

std::cin >> age; // Laisse un '\n' dans le tampon

// On ignore ce qui traîne (ici on lit "dans le vide" pour nettoyer) [00:17:40]
std::cin.ignore(); 

std::getline(std::cin, nom); // Maintenant ça fonctionne !

```

---

### 4. Vérifier l'état de la saisie (Les Flags) [[03:00](http://www.youtube.com/watch?v=tkCCUzIErNU&t=180)]

`std::cin` possède des "drapeaux" pour savoir si la saisie s'est bien passée. C'est crucial pour la gestion d'erreurs.

* **`std::cin.good()`** : Tout va bien. [[03:35](http://www.youtube.com/watch?v=tkCCUzIErNU&t=215)]
* **`std::cin.fail()`** : Erreur de type (ex: on attend un `int` et l'utilisateur tape une lettre). [[04:08](http://www.youtube.com/watch?v=tkCCUzIErNU&t=248)]
* **`std::cin.bad()`** : Erreur irrécupérable sur le flux. [[04:12](http://www.youtube.com/watch?v=tkCCUzIErNU&t=252)]

Si `std::cin` est en état d'erreur, il ne lira plus rien. Il faut utiliser **`std::cin.clear()`** pour réinitialiser les drapeaux. [[08:22](http://www.youtube.com/watch?v=tkCCUzIErNU&t=502)]

---

### Fiche Mémoire Express 📝

| Outil | Usage | Particularité |
| --- | --- | --- |
| **`std::cin >> var`** | Saisie simple | S'arrête aux espaces. |
| **`std::getline(cin, str)`** | Saisie de texte | Lit les espaces, s'arrête à "Entrée". |
| **`std::cin.ignore()`** | Nettoyage | Utile après un `cin >>` avant un `getline`. |
| **`std::cin.fail()`** | Vérification | Renvoie `true` si le type saisi est incorrect. |
| **`std::cin.clear()`** | Réparation | Réactive le flux après une erreur. |

**Petit conseil :** Pensez toujours à l'utilisateur. S'il tape n'importe quoi, votre programme ne doit pas planter. On apprendra à gérer ça plus en détail avec les structures de contrôle. [[22:23](http://www.youtube.com/watch?v=tkCCUzIErNU&t=1343)]

Des questions sur la gestion du tampon ou les erreurs de saisie ? Posez-les en commentaire. La prochaine fois, on attaque les **opérateurs mathématiques** ! À bientôt ! [[22:50](http://www.youtube.com/watch?v=tkCCUzIErNU&t=1370)]