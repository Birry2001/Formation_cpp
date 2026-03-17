Salut à tous ! Bienvenue pour cette douzième séance. Aujourd'hui, on va parler d'un outil super pratique pour rendre votre code plus lisible et plus sûr : les **énumérations** (`enum`).

Une énumération, c'est tout simplement un moyen de définir votre propre type de données qui ne peut prendre que quelques valeurs bien précises que vous avez listées. C'est parfait pour représenter des états, des directions ou des catégories. Allez, on passe sur le code !

---

### 1. L'énumération classique (Régulière) [[00:49](http://www.youtube.com/watch?v=q6AUExuGhyU&t=49)]

On utilise le mot-clé `enum`. Par défaut, chaque nom correspond à un entier (en commençant par 0).

```cpp
#include <iostream>

// Définition de l'énumération [00:01:04]
enum Element {
    TERRE,  // 0
    AIR,    // 1
    FEU,    // 2
    EAU     // 3
};

int main() {
    Element monPouvoir {FEU}; // Utilisation [00:01:47]
    
    // On peut comparer directement
    if (monPouvoir == FEU) {
        std::cout << "C'est chaud !" << std::endl;
    }

    // Affichage : convertit implicitement en entier (affiche 2) [00:02:46]
    std::cout << "Valeur numerique : " << monPouvoir << std::endl;

    return 0;
}

```

**Problème :** Les noms comme `FEU` ou `AIR` sont dans la "portée globale". Si vous créez une autre énumération avec le mot `FEU`, vous aurez un conflit (collision de noms) ! [[06:40](http://www.youtube.com/watch?v=q6AUExuGhyU&t=400)]

---

### 2. L'énumération moderne (Étendue / Scoped Enum) [[06:59](http://www.youtube.com/watch?v=q6AUExuGhyU&t=419)]

Depuis le C++11, on utilise `enum class`. C'est beaucoup plus sûr et c'est ce que je vous recommande d'utiliser par défaut.

```cpp
// On ajoute le mot-clé 'class' [00:07:27]
enum class Nature {
    TERRE,
    AIR,
    FEU,
    EAU
};


int main() {
    // On doit obligatoirement préciser le nom de l'énumération avec '::' [00:08:23]
    Nature monElement = Nature::FEU;

    // Sécurité : Pas de conversion automatique en entier ! [00:08:45]
    // Pour l'afficher, il faut forcer la conversion (cast) [00:09:05]
    std::cout << static_cast<int>(monElement) << std::endl;

    return 0;
}

```
**Avantages :**

* Pas de conflit de noms (on peut avoir `Nature::FEU` et `Magie::FEU`).
* Plus de rigueur : on ne peut pas comparer accidentellement une `Nature` avec un simple `int`. [[11:22](http://www.youtube.com/watch?v=q6AUExuGhyU&t=682)]

---

### 3. Personnaliser les valeurs [[03:04](http://www.youtube.com/watch?v=q6AUExuGhyU&t=184)]

Vous pouvez imposer des valeurs spécifiques si besoin. Les valeurs suivantes s'incrémenteront automatiquement à partir de votre chiffre.

```cpp
enum class CodeErreur : int { // On peut préciser le type sous-jacent [00:13:15]
    OK = 200,
    PAS_TROUVE = 404,
    ERREUR_SERVEUR = 500
};

```

---

### Fiche Mémoire Express 📝

| Type | Syntaxe | Portée | Conversion |
| --- | --- | --- | --- |
| **Classique** | `enum Nom { ... };` | Globale (Risque de conflit) | Implicite (Automatique) |
| **Étendue** | `enum class Nom { ... };` | Locale au type (`Nom::Valeur`) | **Explicite** (`static_cast`) |

**Pourquoi l'utiliser ?**
C'est beaucoup mieux que d'utiliser des chiffres au hasard (ex: `1` pour le feu, `2` pour l'eau). Avec une énumération, votre code "parle" : on lit `Nature::FEU`, c'est clair pour tout le monde ! [[05:11](http://www.youtube.com/watch?v=q6AUExuGhyU&t=311)]

**Votre mission :** Créez une énumération `Direction` (Nord, Sud, Est, Ouest). Demandez à l'utilisateur de choisir une direction et utilisez un `switch` pour afficher un message différent selon son choix. N'oubliez pas le `Nature::` si vous utilisez un `enum class` ! [[14:42](http://www.youtube.com/watch?v=q6AUExuGhyU&t=882)]

Si vous avez des questions sur la différence entre `enum` et `enum class`, les commentaires sont là pour ça. La prochaine fois, on verra d'autres bases avant d'attaquer le gros morceau : la **POO**. À bientôt ! [[15:01](http://www.youtube.com/watch?v=q6AUExuGhyU&t=901)]