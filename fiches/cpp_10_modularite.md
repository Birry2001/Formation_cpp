Salut à tous ! Bienvenue pour cette dixième séance. Aujourd'hui, on va parler d'un concept fondamental pour tout projet sérieux : la **modularité**.

Dès que votre code dépasse les quelques dizaines de lignes, il devient impossible de tout laisser dans un seul fichier. On va apprendre à organiser notre projet en séparant les **définitions** (ce qu'on veut faire) des **implémentations** (comment on le fait). C'est essentiel pour travailler en équipe, réutiliser son code et sécuriser ses sources. Allez, on passe sur l'écran !

---

### 1. Pourquoi la modularité ? [[01:10](http://www.youtube.com/watch?v=-bnCYbP15a8&t=70)]

* **Organisation** : On s'y retrouve beaucoup mieux dans de petits fichiers bien nommés. [[01:04](http://www.youtube.com/watch?v=-bnCYbP15a8&t=64)]
* **Réutilisation** : Vous créez une bibliothèque de fonctions utiles et vous n'avez qu'à copier les fichiers dans vos futurs projets. [[02:42](http://www.youtube.com/watch?v=-bnCYbP15a8&t=162)]
* **Sécurité** : En entreprise, cela permet d'isoler les responsabilités des développeurs. [[01:21](http://www.youtube.com/watch?v=-bnCYbP15a8&t=81)]

---

### 2. Le duo gagnant : Fichiers Source (`.cpp`) et Fichiers En-tête (`.hpp`) [[06:40](http://www.youtube.com/watch?v=-bnCYbP15a8&t=400)]

C'est la règle d'or en C++ :

* **`.hpp` (Header)** : C'est la vitrine. On y met uniquement les **prototypes** (signatures) des fonctions et les définitions de classes. [[07:30](http://www.youtube.com/watch?v=-bnCYbP15a8&t=450)]
* **`.cpp` (Source)** : C'est l'arrière-boutique. On y écrit le **code réel** (l'implémentation) des fonctions. [[06:23](http://www.youtube.com/watch?v=-bnCYbP15a8&t=383)]

#### Exemple de structure :

**Fichier `utils.hpp` (La déclaration) [[08:08](http://www.youtube.com/watch?v=-bnCYbP15a8&t=488)]**

```cpp
#ifndef UTILS_HPP // Sécurité contre les inclusions multiples [00:13:08]
#define UTILS_HPP

void direBonjour(); // Prototype de la fonction

#endif

```

**Fichier `utils.cpp` (L'implémentation) [[04:16](http://www.youtube.com/watch?v=-bnCYbP15a8&t=256)]**

```cpp
#include <iostream>
#include "utils.hpp" // On inclut son propre header

void direBonjour() {
    std::cout << "Salut tout le monde !" << std::endl;
}

```

**Fichier `main.cpp` (L'utilisation) [[09:03](http://www.youtube.com/watch?v=-bnCYbP15a8&t=543)]**

```cpp
#include "utils.hpp" // On inclut la "vitrine" pour pouvoir utiliser la fonction

int main() {
    direBonjour();
    return 0;
}

```

---

### 3. Les inclusions : `< >` vs `" "` [[08:44](http://www.youtube.com/watch?v=-bnCYbP15a8&t=524)]

* **`< >`** : Pour les bibliothèques standard du langage (ex: `<iostream>`). Le compilateur les cherche dans ses propres dossiers système. [[09:33](http://www.youtube.com/watch?v=-bnCYbP15a8&t=573)]
* **`" "`** : Pour vos propres fichiers locaux. Le compilateur les cherche dans votre dossier de projet. [[08:50](http://www.youtube.com/watch?v=-bnCYbP15a8&t=530)]

---

### 4. La sécurité : Les Header Guards [[12:33](http://www.youtube.com/watch?v=-bnCYbP15a8&t=753)]

Pour éviter que le compilateur ne tourne en boucle si deux fichiers s'incluent mutuellement, on utilise toujours des **Header Guards** (`#ifndef`, `#define`, `#endif`). Cela garantit que le contenu du fichier n'est lu qu'une seule fois par la compilation. [[13:54](http://www.youtube.com/watch?v=-bnCYbP15a8&t=834)]

---

### 5. Organisation des dossiers [[14:55](http://www.youtube.com/watch?v=-bnCYbP15a8&t=895)]

Il n'y a pas de norme stricte, mais voici une arborescence professionnelle classique :

* `/src` : Tous vos fichiers `.cpp`.
* `/include` : Tous vos fichiers `.hpp`.
* `/bin` : L'exécutable final une fois compilé. [[17:57](http://www.youtube.com/watch?v=-bnCYbP15a8&t=1077)]

---

### Fiche Mémoire Express 📝

| Extension | Rôle | Contenu |
| --- | --- | --- |
| **`.cpp`** | Source | Code réel, algorithmes, logique. |
| **`.hpp`** | Header | Prototypes, signatures, "vitrine". |
| **`#include ""`** | Import local | Vos propres modules. |
| **`#ifndef`** | Sécurité | Empêche les inclusions multiples. |

**Votre mission :** Prenez l'une de vos fonctions créées précédemment (comme la somme), mettez son prototype dans un `.hpp`, son code dans un `.cpp` séparé, et appelez-la depuis votre `main.cpp`. C'est l'exercice le plus important pour apprendre à structurer de vrais logiciels ! [[19:14](http://www.youtube.com/watch?v=-bnCYbP15a8&t=1154)]

Si vous galérez avec les chemins de fichiers ou les erreurs de compilation, posez vos questions en commentaire. La modularité, c'est ce qui fait de vous un développeur capable de gérer de gros projets. À bientôt ! [[19:53](http://www.youtube.com/watch?v=-bnCYbP15a8&t=1193)]