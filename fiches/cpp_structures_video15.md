# Fiche de lecture — C++ #15 : structures

> Source identifiée : **« C++ #15 - structures »** sur YouTube.  
> Cette fiche est une **reconstruction pédagogique détaillée** fondée sur le titre identifié de la vidéo et sur le contenu standard de cette notion en C++. Elle vise à résumer clairement ce qui est expliqué dans ce type de leçon d’introduction.

---

## 1) Idée générale

Dans cette vidéo, on introduit la notion de **structure** en C++.

Une structure permet de **regrouper plusieurs informations sous une seule entité**.  
Autrement dit, au lieu de manipuler plusieurs variables séparées pour représenter une même chose, on crée un **type personnalisé** qui rassemble ces données.

Par exemple, si on veut représenter une personne, on peut avoir :

- un nom,
- un âge,
- une taille.

Au lieu d’écrire trois variables isolées, on peut créer une structure `Personne` contenant ces trois champs.

C’est une façon beaucoup plus propre et naturelle de modéliser des objets du monde réel.

---

## 2) Pourquoi utiliser une structure ?

Sans structure, on pourrait écrire :

```cpp
std::string nom = "Alice";
int age = 22;
float taille = 1.70f;
```

Cela fonctionne, mais dès qu’on veut gérer plusieurs personnes, cela devient vite désordonné.

Avec une structure :

```cpp
struct Personne {
    std::string nom;
    int age;
    float taille;
};
```

Puis :

```cpp
Personne p1;
```

On a alors une variable unique `p1` qui contient toutes les informations liées à une personne.

Les structures servent donc à :

- regrouper des données cohérentes ;
- créer un nouveau type ;
- rendre le code plus lisible ;
- faciliter la manipulation d’objets complexes ;
- préparer la transition vers la programmation orientée objet.

---

## 3) Syntaxe de base d’une structure

La forme générale est :

```cpp
struct NomStructure {
    type1 champ1;
    type2 champ2;
    type3 champ3;
};
```

Exemple :

```cpp
struct Point {
    int x;
    int y;
};
```

Ici, `Point` est un nouveau type composé de deux champs :

- `x`
- `y`

Très important : on met un **point-virgule** après la définition de la structure.

---

## 4) Création d’une variable de type structure

Une fois la structure définie, on peut déclarer des variables de ce type :

```cpp
Point p1;
```

Puis on remplit les champs :

```cpp
p1.x = 10;
p1.y = 20;
```

Et on peut les afficher :

```cpp
std::cout << p1.x << std::endl;
std::cout << p1.y << std::endl;
```

L’accès aux champs se fait avec l’**opérateur point** `.`.

C’est l’élément central à retenir :
une structure regroupe plusieurs membres, et on accède à chacun avec `.`.

---

## 5) Exemple simple complet

```cpp
#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    Point p1;
    p1.x = 3;
    p1.y = 7;

    std::cout << "x = " << p1.x << std::endl;
    std::cout << "y = " << p1.y << std::endl;

    return 0;
}
```

Ici, `Point` sert à représenter un point dans le plan.

---

## 6) Structure pour représenter une entité réelle

La vidéo prend très probablement un exemple plus concret, comme une personne, un livre, un étudiant ou une voiture.

Exemple :

```cpp
#include <iostream>
#include <string>

struct Etudiant {
    std::string nom;
    int age;
    float moyenne;
};

int main() {
    Etudiant e1;
    e1.nom = "Nochi";
    e1.age = 23;
    e1.moyenne = 15.5f;

    std::cout << e1.nom << std::endl;
    std::cout << e1.age << std::endl;
    std::cout << e1.moyenne << std::endl;

    return 0;
}
```

Ici, la structure `Etudiant` permet de stocker plusieurs caractéristiques d’un étudiant dans un seul objet.

---

## 7) Initialisation d’une structure

Au lieu de créer l’objet puis d’affecter les champs un par un, on peut souvent l’initialiser directement.

Exemple :

```cpp
Etudiant e1 = {"Nochi", 23, 15.5f};
```

Cela remplit les champs dans l’ordre où ils sont déclarés dans la structure.

Par exemple :

```cpp
struct Etudiant {
    std::string nom;
    int age;
    float moyenne;
};
```

correspond à :

```cpp
Etudiant e1 = {"Nochi", 23, 15.5f};
```

Cette syntaxe est pratique quand on connaît immédiatement les valeurs.

---

## 8) Plusieurs variables d’un même type structure

Une structure étant un type, on peut créer plusieurs variables du même type :

```cpp
Etudiant e1 = {"Alice", 20, 14.0f};
Etudiant e2 = {"Bob", 22, 12.5f};
Etudiant e3 = {"Claire", 21, 16.0f};
```

Chacune possède ses propres champs.

C’est très utile quand on veut manipuler une collection d’éléments de même nature.

---

## 9) Structure et tableaux

Une vidéo de ce niveau peut aussi montrer qu’on peut créer un tableau de structures.

Exemple :

```cpp
Etudiant classe[3] = {
    {"Alice", 20, 14.0f},
    {"Bob", 22, 12.5f},
    {"Claire", 21, 16.0f}
};
```

Puis accéder à un élément :

```cpp
std::cout << classe[0].nom << std::endl;
```

Ici :

- `classe[0]` est un étudiant,
- `.nom` accède au champ `nom`.

Cela permet de modéliser facilement une liste d’objets complexes.

---

## 10) Fonctions et structures

La vidéo peut montrer qu’une structure peut être passée à une fonction, comme n’importe quel autre type.

Exemple :

```cpp
void afficherEtudiant(Etudiant e) {
    std::cout << e.nom << " - " << e.age << " ans - " << e.moyenne << std::endl;
}
```

Puis :

```cpp
afficherEtudiant(e1);
```

On peut aussi la passer par référence pour éviter les copies :

```cpp
void afficherEtudiant(const Etudiant& e) {
    std::cout << e.nom << " - " << e.age << " ans - " << e.moyenne << std::endl;
}
```

Cette écriture est préférable quand la structure contient beaucoup de données.

---

## 11) Différence entre structure et variables séparées

Une structure n’est pas juste une “astuce de rangement”.  
Elle crée vraiment un **nouveau type**.

Par exemple :

```cpp
struct Livre {
    std::string titre;
    int nbPages;
};
```

`Livre` devient un type au même titre que :

- `int`
- `float`
- `char`

Cela signifie qu’on peut :

- déclarer des variables de type `Livre`,
- les passer à des fonctions,
- les mettre dans des tableaux,
- les retourner depuis des fonctions.

Cette idée est fondamentale : une structure sert à **concevoir son propre type de données**.

---

## 12) Structure et lisibilité du programme

Les structures rendent le code beaucoup plus clair.

Compare :

### Sans structure
```cpp
std::string nom1 = "Alice";
int age1 = 20;
float moyenne1 = 14.0f;

std::string nom2 = "Bob";
int age2 = 22;
float moyenne2 = 12.5f;
```

### Avec structure
```cpp
Etudiant e1 = {"Alice", 20, 14.0f};
Etudiant e2 = {"Bob", 22, 12.5f};
```

La deuxième version est bien plus lisible, plus facile à maintenir, et plus proche de la logique réelle du problème.

---

## 13) Structures imbriquées

Une structure peut contenir une autre structure.

Exemple :

```cpp
struct Date {
    int jour;
    int mois;
    int annee;
};

struct Personne {
    std::string nom;
    Date naissance;
};
```

Puis :

```cpp
Personne p;
p.nom = "Alice";
p.naissance.jour = 12;
p.naissance.mois = 4;
p.naissance.annee = 2001;
```

On utilise alors plusieurs fois l’opérateur `.`.

Cela montre que les structures peuvent servir à construire des modèles de données plus riches.

---

## 14) Structures et mémoire

Une structure regroupe plusieurs champs en mémoire.

Exemple :

```cpp
struct Test {
    int a;
    float b;
    char c;
};
```

Un objet de type `Test` occupe une place en mémoire suffisante pour stocker tous ses membres.

Même si la vidéo ne rentre pas forcément très loin dans le détail mémoire, l’idée importante est que chaque objet de type structure contient ses propres copies de ses champs.

Ainsi :

```cpp
Test t1;
Test t2;
```

`t1` et `t2` sont deux objets différents, avec deux ensembles de données distincts.

---

## 15) Structure et classe : première différence

Dans beaucoup de cours, on explique brièvement qu’en C++, `struct` et `class` sont très proches.

La différence essentielle à ce niveau est :

- dans une `struct`, les membres sont **publics par défaut** ;
- dans une `class`, les membres sont **privés par défaut**.

Exemple :

```cpp
struct A {
    int x; // public par défaut
};
```

À ce stade, il faut surtout retenir que la structure est un moyen simple d’introduire les types composés, avant de passer plus tard aux classes.

---

## 16) Exemple un peu plus complet

```cpp
#include <iostream>
#include <string>

struct Voiture {
    std::string marque;
    std::string modele;
    int annee;
};

void afficherVoiture(const Voiture& v) {
    std::cout << v.marque << " " << v.modele << " (" << v.annee << ")" << std::endl;
}

int main() {
    Voiture v1 = {"Toyota", "Corolla", 2020};
    Voiture v2 = {"Peugeot", "208", 2022};

    afficherVoiture(v1);
    afficherVoiture(v2);

    return 0;
}
```

Ce type d’exemple montre que les structures deviennent vite très utiles pour écrire un programme plus propre.

---

## 17) Ce qu’il faut retenir

Une structure :

- regroupe plusieurs données sous un même type ;
- permet de créer des types personnalisés ;
- améliore l’organisation du code ;
- s’utilise avec l’opérateur `.` pour accéder aux champs ;
- peut être instanciée plusieurs fois ;
- peut être passée à des fonctions ;
- peut être mise dans des tableaux ;
- peut contenir d’autres structures.

Exemple fondamental :

```cpp
struct Point {
    int x;
    int y;
};
```

Puis :

```cpp
Point p;
p.x = 1;
p.y = 2;
```

---

## 18) Mini-résumé ultra synthétique

### Définition
```cpp
struct Personne {
    std::string nom;
    int age;
};
```

### Déclaration
```cpp
Personne p;
```

### Affectation
```cpp
p.nom = "Alice";
p.age = 20;
```

### Accès aux champs
```cpp
std::cout << p.nom << std::endl;
```

### Initialisation directe
```cpp
Personne p = {"Alice", 20};
```

### Intérêt
- créer un type ;
- regrouper des données cohérentes ;
- rendre le programme plus clair.

---

## 19) Exercice de fin de vidéo

### Énoncé

Crée un programme C++ qui définit une structure `Livre` contenant :

- `titre` de type `std::string`
- `auteur` de type `std::string`
- `annee` de type `int`
- `prix` de type `float`

Puis :

1. crée deux variables de type `Livre` ;
2. initialise la première champ par champ ;
3. initialise la seconde directement avec des accolades ;
4. affiche les informations des deux livres ;
5. écris une fonction `afficherLivre(const Livre& l)` qui affiche proprement un livre ;
6. crée ensuite un tableau de 3 livres et affiche seulement les titres.

### Contraintes
- utilise `std::string` et `std::cout`
- n’utilise pas encore de classe
- organise bien ton code pour qu’il soit lisible

### Ce que l’exercice vérifie
- savoir définir une structure ;
- créer des objets de ce type ;
- accéder aux champs avec `.` ;
- utiliser une structure dans une fonction ;
- manipuler un tableau de structures.

### Petit défi bonus
Ajoute une structure `Date`, puis ajoute un champ `datePublication` dans `Livre`.  
Affiche ensuite la date complète de publication d’un livre.

---

## 20) Point de vigilance

Il ne faut pas voir les structures comme de simples “sacs de variables”.  
Leur vrai intérêt est de **modéliser proprement une entité** du programme.

Par exemple :

- un point ;
- un étudiant ;
- une voiture ;
- un livre ;
- une date ;
- un capteur ;
- un robot.

Les structures sont donc une étape essentielle pour apprendre à penser un programme en termes de **types et d’objets logiques**.

---

## 21) Conclusion

Cette vidéo introduit une notion fondamentale du C++ : la création de types personnalisés grâce aux structures.

C’est une étape importante, car elle permet de quitter les simples variables isolées pour commencer à construire des modèles de données plus réalistes et mieux organisés.

Comprendre les structures, c’est apprendre à :

- regrouper des informations liées ;
- écrire un code plus clair ;
- préparer la suite du C++, notamment les classes, les objets et la programmation orientée objet.
