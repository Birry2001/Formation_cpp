Salut à tous ! Bienvenue pour cette onzième séance. Aujourd'hui, on s'attaque à un sujet crucial pour rendre vos programmes robustes et professionnels : la **gestion des erreurs**.

Il y a deux mondes différents à gérer : les erreurs que vous faites, vous, en tant que **développeur**, et les imprévus causés par l'**utilisateur** final ou l'environnement. On va voir comment traiter ces deux cas proprement. Allez, on passe sur le code !

---

### 1. Les erreurs du Développeur : Les Assertions [[01:49](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=109)]

Une assertion, c'est un test que vous placez dans votre code pendant la phase de développement. Si l'expression est fausse, le programme s'arrête net. C'est pour débusquer vos propres étourderies (ex: créer un personnage de niveau négatif).

```cpp
#include <cassert> // Obligatoire pour utiliser les assertions [00:04:58]

void creerPersonnage(std::string nom, int niveau) {
    // On affirme que le niveau doit être strictement supérieur à 0 [00:05:44]
    assert(niveau > 0 && "Le niveau doit etre positif !"); 
    
    std::cout << "Personnage " << nom << " cree au niveau " << niveau << std::endl;
}

```

**À savoir :**

* L'assertion ne sert que pour le **débogage**.
* En production (version finale), on les désactive avec l'argument `-DNDEBUG` lors de la compilation pour ne pas ralentir le programme. [[08:39](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=519)]

---

### 2. Les erreurs de l'Utilisateur : Les Exceptions [[10:33](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=633)]

Contrairement aux assertions, les exceptions gèrent les erreurs qui arrivent à l'**exécution** (problème réseau, fichier manquant, mauvaise saisie). On ne veut pas que le programme plante, on veut "capturer" l'erreur pour l'expliquer à l'utilisateur.

#### La structure `try... catch` [[14:41](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=881)]

```cpp
#include <iostream>
#include <stdexcept> // Pour les types d'exceptions standards [00:11:11]

int main() {
    try {
        // Bloc de code "sensible" qui peut lever une erreur [00:14:46]
        int age;
        std::cin >> age;
        if (age < 0) {
            throw std::invalid_argument("L'age ne peut pas etre negatif !"); // On lève l'exception [00:18:40]
        }
    } 
    catch (const std::invalid_argument &e) { // On capture l'erreur précise [00:15:52]
        std::cerr << "Erreur de saisie : " << e.what() << std::endl;
    }
    catch (const std::exception &e) { // Capture globale (secours) [00:17:32]
        std::cerr << "Une erreur inattendue est survenue : " << e.what() << std::endl;
    }

    return 0;
}

```

---

### 3. Lever ses propres exceptions avec `throw` [[18:40](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=1120)]

Vous pouvez déclencher manuellement une exception si une condition métier n'est pas respectée. Cela permet d'interrompre proprement le flux actuel pour remonter l'info.

---

### Fiche Mémoire Express 📝

| Outil | Cible | Quand ? | Résultat |
| --- | --- | --- | --- |
| **`assert(expr)`** | Le Développeur | Développement / Debug | Arrêt brutal du programme. |
| **`try { }`** | Code à risque | Exécution / Production | Tente d'exécuter un bloc. |
| **`throw`** | Signal d'erreur | Exécution / Production | "Lance" un objet d'erreur. |
| **`catch(e)`** | Gestion d'erreur | Exécution / Production | "Attrape" l'erreur pour la traiter. |

**Votre mission :** Reprenez votre programme de calcul et utilisez un `throw` si l'utilisateur tente une division par zéro. Capturez cette erreur avec un `catch` pour lui afficher un message poli au lieu de laisser le programme planter. [[22:10](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=1330)]

Si vous avez des doutes sur l'utilisation du `std::exception` ou du `e.what()`, posez vos questions en commentaire. C'est en sécurisant votre code que vous devenez un vrai pro ! À bientôt ! [[22:28](http://www.youtube.com/watch?v=6MnuOOr1iZ8&t=1348)]