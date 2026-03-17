Salut à tous ! Bienvenue pour cette deuxième séance. J'espère que vous avez la forme. Aujourd'hui, on passe aux choses sérieuses : on va écrire et compiler notre tout **premier programme en C++**.

Si c'est votre premier langage, pas de panique, on va faire ça étape par étape, très simplement. Allez, on passe sur l'écran !

---

### 1. Préparation du fichier source [[00:23](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=23)]

Avant de coder, il nous faut un fichier. Je pars du principe que vous n'avez jamais programmé. Sur votre bureau ou dans un dossier :

* Faites un **clic droit > Nouveau > Fichier texte**.
* Renommez-le impérativement avec l'extension **`.cpp`** (par exemple `main.cpp`).
* *Petite parenthèse :* Si vous êtes sur Windows, assurez-vous de bien afficher les extensions de fichiers, sinon vous allez créer un `main.cpp.txt` et ça ne marchera jamais ! [[00:41](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=41)]

Ouvrez ce fichier avec votre éditeur (VS Code ou autre) et vérifiez bien que vous êtes en **encodage UTF-8** pour éviter les bugs bizarres. [[02:36](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=156)]

---

### 2. Le code minimal (Hello World) [[02:54](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=174)]

On va écrire quelques lignes. C'est le "squelette" de base de tout programme C++. Chaque chose ici a une importance capitale.

```cpp
#include <iostream> // Directive de préprocesseur [00:03:15]

int main() // Point d'entrée obligatoire du programme [00:04:01]
{
    // Affichage d'un message sur la console
    std::cout << "Hello World !" << std::endl; [00:07:46]

    return 0; // On indique que tout s'est bien passé [00:07:07]
}

```

**Ce qu'il faut retenir :**

* **`#include <iostream>`** : On demande d'inclure les outils pour gérer les entrées et sorties (Input/Output). Sans ça, impossible d'afficher du texte. [[03:23](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=203)]
* **`int main()`** : C'est le cerveau de votre programme. Le C++ cherche toujours cette fonction pour démarrer. Pas de `main`, pas de programme ! [[04:13](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=253)]
* **Les accolades `{ }**` : Elles délimitent le bloc de code de votre fonction. [[05:02](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=302)]
* **La casse** : Le C++ est **sensible à la casse**. `Main()` avec un M majuscule, ça ne marchera pas. Respectez bien les minuscules. [[05:30](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=330)]
* **Le point-virgule `;**` : Chaque instruction doit se terminer par un point-virgule. C'est ce qui permet au compilateur de séparer les ordres. [[08:46](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=526)]

---

### 3. Compilation et Exécution [[10:00](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=600)]

Maintenant, on va transformer ce texte en un fichier que l'ordinateur comprend (un exécutable). Ouvrez votre terminal (PowerShell, CMD ou terminal Linux/Mac).

Placez-vous dans le bon répertoire avec la commande `cd` [[11:23](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=683)], puis tapez cette ligne de commande (c'est notre "formule magique" pour compiler) :

```bash
# Commande de compilation ultra-pro [00:11:43]
g++ -std=c++17 -Wall -Wextra -Werror main.cpp -o prog

```

**Détails des options :**

* `-std=c++17` : On utilise la norme C++ de 2017 (le standard). [[11:54](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=714)]
* `-Wall -Wextra -Werror` : C'est le mode "strict". On demande au compilateur de nous signaler la moindre petite erreur ou oubli. C'est comme ça qu'on apprend à coder proprement ! [[12:30](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=750)]
* `main.cpp` : Votre fichier source.
* `-o prog` : On donne un nom à notre programme final (ici `prog`).

Une fois compilé, pour l'exécuter, tapez simplement :

```bash
./prog

```

Et là, normalement, vous voyez s'afficher **"Hello World !"**. Félicitations, vous venez de créer votre premier logiciel ! [[13:03](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=783)]

---

### Petit résumé pour la suite [[13:50](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=830)]

N'oubliez pas :

1. **Directives** en haut (`#include`).
2. **Fonction `main**` au milieu.
3. **Instructions** terminées par des `;`.
4. **Compilation** rigoureuse avec les bonnes options.

Si vous avez des soucis, notamment avec l'installation du compilateur ou l'encodage, n'hésitez pas à poser vos questions en commentaire. On avance vite dès la prochaine séance !

À bientôt pour la suite de cette formation ! [[14:53](http://www.youtube.com/watch?v=FjG4HYo-Jm0&t=893)]