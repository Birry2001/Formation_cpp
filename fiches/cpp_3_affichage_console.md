Salut à tous ! Content de vous retrouver pour cette séance 3. J'espère que vous avez bien digéré votre premier programme, parce qu'aujourd'hui on va décortiquer l'**affichage console**.

On a vu le `Hello World`, mais il y a des concepts derrière qui sont cruciaux pour éviter des bugs bizarres plus tard, surtout quand vous travaillerez sur des fichiers. Allez, on passe sur le code !

---

### 1. Les différents flux de sortie [[03:32](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=212)]

En C++, on ne se contente pas d'afficher du texte "en vrac". On sépare les types d'informations grâce à trois objets de la bibliothèque standard (`std`).

```cpp
#include <iostream>

int main() {
    // 1. Sortie standard (Standard Output) [00:04:06]
    // Pour les messages classiques du programme.
    std::cout << "Message classique" << std::endl;

    // 2. Sortie d'erreur standard (Standard Error) [00:04:45]
    // Pour afficher les erreurs. Certains systèmes traitent ce flux différemment.
    std::cerr << "Oups, une erreur est survenue !" << std::endl;

    // 3. Journalisation (Standard Log) [00:07:02]
    // Pour garder un historique (logs) des actions du programme.
    std::clog << "Action de l'utilisateur enregistree" << std::endl;

    return 0;
}

```

---

### 2. La Mémoire Tampon (Buffer) et le Flush [[07:24](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=444)]

C'est là que ça devient technique mais super important.

* Votre ordinateur n'écrit pas chaque lettre sur l'écran ou le disque au fur et à mesure (ce serait trop lent). Il les stocke dans une **mémoire tampon** (un buffer). [[08:43](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=523)]
* Le **Flush** (vidange), c'est l'action de vider ce tampon pour forcer l'affichage réel. [[08:56](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=536)]

**Comparatif important [[16:34](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=994)] :**

* `std::cout` et `std::clog` utilisent une mémoire tampon (ils attendent avant d'afficher).
* `std::cerr` n'a **pas de mémoire tampon** : l'affichage est direct et immédiat. C'est fait exprès pour que vous voyiez l'erreur même si le programme plante juste après. [[17:05](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=1025)]

---

### 3. Retour à la ligne : `endl` vs `\n` [[12:00](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=720)]

On a utilisé `std::endl`, mais il y a une grosse différence avec le caractère spécial `\n`.

```cpp
// endl fait DEUX choses : retour à la ligne + Flush [00:12:06]
std::cout << "Texte" << std::endl; 

// \n fait UNE seule chose : retour à la ligne [00:19:01]
std::cout << "Texte\n"; 

```

**Conseil d'expert :** Si vous écrivez des milliers de lignes dans un fichier, n'utilisez pas `endl` à chaque fois, car faire un "Flush" à chaque ligne ralentit énormément le programme. Préférez `\n`. [[22:46](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=1366)]

---

### 4. Les caractères spéciaux et commentaires [[13:40](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=820)]

Pour documenter votre code (c'est vital pour s'y retrouver plus tard !), on utilise les commentaires :

```cpp
// Commentaire sur une seule ligne [00:14:24]

/* Commentaire 
   sur plusieurs 
   lignes (documentation) [00:14:32]
*/

// Quelques caractères spéciaux utiles [00:18:50] :
// \n : retour à la ligne
// \t : tabulation (retrait de texte) [00:19:21]
// \\ : pour afficher un vrai backslash [00:19:43]

```

---

### Fiche Mémoire Express 📝

| Outil | Rôle | Spécificité |
| --- | --- | --- |
| `std::cout` | Affichage standard | Avec mémoire tampon. |
| `std::cerr` | Affichage d'erreur | **Sans** mémoire tampon (immédiat). |
| `std::clog` | Journalisation | Avec mémoire tampon. |
| `std::endl` | Saut de ligne | **Force** la vidange du tampon (Flush). |
| `\n` | Saut de ligne | Simple, plus rapide pour les gros volumes. |

Voilà pour l'affichage ! Prenez bien le temps de comprendre cette histoire de mémoire tampon, c'est ce qui différencie un débutant d'un vrai programmeur.

Prochaine étape : on va apprendre à mémoriser des informations avec les **variables**. C'est un gros morceau, alors soyez au rendez-vous ! [[27:13](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=1633)]

Si vous avez des questions sur le buffer ou les flux, direction les commentaires. À bientôt ! [[27:37](http://www.youtube.com/watch?v=lS4sXuTXkyI&t=1657)]