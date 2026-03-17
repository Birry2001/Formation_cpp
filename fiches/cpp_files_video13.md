# Fiche de lecture — C++ #13 : files

> Vidéo identifiée : **“C++ #13 - files”**. La vidéo traite de la gestion des flux de données en C++ pour **lire** et **écrire** dans des fichiers, en **mode texte** ou **binaire**. citeturn395179search0

---

## 1. Idée générale de la vidéo

Cette vidéo introduit un point très important en C++ : **la persistance des données**.

Jusqu’ici, dans beaucoup de petits programmes, les données vivent seulement pendant l’exécution : on lance le programme, on manipule des variables, puis tout disparaît quand le programme s’arrête. Avec les **fichiers**, on peut au contraire :

- enregistrer des résultats,
- relire des données plus tard,
- conserver une configuration,
- stocker des logs,
- charger des ressources nécessaires à un programme.

La vidéo explique donc comment C++ permet de manipuler des fichiers à travers la bibliothèque standard, en particulier avec les **flux de fichiers**.

---

## 2. Les flux en C++

Le cœur de la logique repose sur la notion de **stream** (*flux*).

Un flux est un canal par lequel les données circulent.

On retrouve généralement trois familles :

```cpp
#include <iostream>
#include <fstream>
```

- `std::cin` : flux d’entrée standard, généralement le clavier.
- `std::cout` : flux de sortie standard, généralement le terminal.
- Les flux de fichiers : pour lire/écrire dans des fichiers.

L’idée pédagogique importante est la suivante :

- écrire dans un fichier ressemble beaucoup à écrire dans `std::cout`,
- lire depuis un fichier ressemble beaucoup à lire avec `std::cin`.

Autrement dit, on garde une logique familière, mais la source ou la destination des données change.

---

## 3. Les classes principales pour les fichiers

La vidéo présente en général les trois classes les plus utiles de `<fstream>`.

### `std::ofstream`

```cpp
std::ofstream file;
```

- `o` pour **output**.
- Sert à **écrire** dans un fichier.

### `std::ifstream`

```cpp
std::ifstream file;
```

- `i` pour **input**.
- Sert à **lire** depuis un fichier.

### `std::fstream`

```cpp
std::fstream file;
```

- Sert à faire **lecture + écriture**.
- Plus général, mais parfois un peu moins lisible pour débuter.

---

## 4. Ouvrir un fichier

Il y a deux manières courantes d’ouvrir un fichier.

### a) À la construction

```cpp
std::ofstream file("output.txt");
```

Ici, le fichier est ouvert dès la création de l’objet.

### b) Avec `open()`

```cpp
std::ofstream file;
file.open("output.txt");
```

Cette deuxième forme est utile quand le nom du fichier est obtenu plus tard dans le programme.

---

## 5. Vérifier si l’ouverture a réussi

C’est une étape essentielle.

Un fichier peut ne pas s’ouvrir si :

- le chemin est faux,
- le fichier n’existe pas en lecture,
- les permissions sont insuffisantes,
- le disque ou le système pose problème.

Exemple classique :

```cpp
std::ifstream file("data.txt");

if (!file) {
    std::cout << "Erreur lors de l'ouverture du fichier\n";
}
```

ou encore :

```cpp
if (file.is_open()) {
    std::cout << "Fichier ouvert\n";
}
```

### À retenir

- `file.is_open()` vérifie si le fichier est ouvert.
- `if (!file)` permet souvent de détecter un échec d’ouverture ou un état invalide du flux.

---

## 6. Écrire dans un fichier texte

Une fois le fichier ouvert avec `std::ofstream`, l’écriture ressemble à `std::cout`.

```cpp
std::ofstream file("notes.txt");

file << "Bonjour" << std::endl;
file << 42 << std::endl;
file << 3.14 << std::endl;
```

### Ce qu’il faut comprendre

- L’opérateur `<<` envoie les données dans le fichier.
- `std::endl` ajoute un saut de ligne et force généralement un flush.
- Le contenu est écrit **sous forme texte**.

Si on ouvre ensuite `notes.txt`, on verra quelque chose de lisible par un humain.

---

## 7. Fermer un fichier

On peut fermer explicitement le fichier :

```cpp
file.close();
```

En pratique, l’objet ferme aussi le fichier automatiquement quand il sort de portée, mais il est utile de comprendre `close()`.

### Pourquoi fermer explicitement peut être utile ?

- pour libérer immédiatement la ressource,
- pour s’assurer que l’écriture est terminée,
- pour rouvrir le même fichier ensuite dans un autre mode.

---

## 8. Lire un fichier texte

Pour lire un fichier, on utilise `std::ifstream`.

### a) Lecture mot par mot

```cpp
std::ifstream file("data.txt");
std::string word;

while (file >> word) {
    std::cout << word << std::endl;
}
```

Ici, l’opérateur `>>` lit des blocs séparés par des espaces, tabulations ou retours à la ligne.

### b) Lecture ligne par ligne

```cpp
std::ifstream file("data.txt");
std::string line;

while (std::getline(file, line)) {
    std::cout << line << std::endl;
}
```

Cette méthode est fondamentale lorsqu’on veut préserver les espaces d’une ligne.

---

## 9. Différence entre `>>` et `getline()`

C’est souvent un point important dans ce type de vidéo.

### Avec `>>`

```cpp
file >> word;
```

- lit jusqu’au prochain séparateur blanc,
- ignore les espaces successifs,
- ne lit pas toute une phrase d’un coup.

### Avec `getline()`

```cpp
std::getline(file, line);
```

- lit toute la ligne,
- conserve les espaces à l’intérieur de la ligne,
- s’arrête au retour à la ligne.

### Exemple

Si le fichier contient :

```text
Bonjour tout le monde
```

- avec `>>`, on lira successivement `Bonjour`, puis `tout`, puis `le`, puis `monde` ;
- avec `getline()`, on lira `Bonjour tout le monde` en une seule fois.

---

## 10. Les modes d’ouverture

La vidéo mentionne généralement qu’un fichier peut être ouvert avec différents **modes**.

Exemples classiques :

```cpp
std::ofstream file("output.txt", std::ios::app);
```

### `std::ios::out`

- mode écriture.
- souvent implicite pour `ofstream`.

### `std::ios::in`

- mode lecture.
- souvent implicite pour `ifstream`.

### `std::ios::app`

- **append**.
- ajoute les nouvelles données à la fin du fichier.
- évite d’écraser le contenu existant.

### `std::ios::trunc`

- tronque le fichier.
- son contenu précédent est effacé.
- souvent utilisé implicitement quand on ouvre un `ofstream` simple.

### `std::ios::binary`

- ouvre le fichier en mode binaire.
- important pour écrire/lire des octets bruts plutôt qu’un texte interprété.

### Exemple combiné

```cpp
std::ofstream file("data.bin", std::ios::out | std::ios::binary);
```

---

## 11. Écraser ou ajouter ?

C’est une distinction très importante.

### Écriture normale

```cpp
std::ofstream file("journal.txt");
```

Dans beaucoup de cas, cela **écrase** le contenu précédent.

### Écriture en ajout

```cpp
std::ofstream file("journal.txt", std::ios::app);
```

Ici, on ajoute les nouvelles données à la fin.

### Quand utiliser `app` ?

- journalisation de messages,
- historique,
- sauvegarde progressive,
- accumulation de résultats.

---

## 12. Le mode binaire

La source indique explicitement que la vidéo parle de lecture/écriture en **mode texte ou binaire**. citeturn395179search0

### Qu’est-ce que cela signifie ?

En mode texte, les données sont écrites sous une forme lisible.

En mode binaire, on écrit directement la représentation mémoire de certaines données ou une suite d’octets.

Exemple :

```cpp
int value = 123;
std::ofstream file("number.bin", std::ios::binary);
file.write(reinterpret_cast<char*>(&value), sizeof(value));
```

Et pour relire :

```cpp
int value = 0;
std::ifstream file("number.bin", std::ios::binary);
file.read(reinterpret_cast<char*>(&value), sizeof(value));
```

---

## 13. `write()` et `read()`

Quand on manipule du binaire, on n’utilise pas principalement `<<` et `>>`, mais plutôt :

```cpp
file.write(...);
file.read(...);
```

### `write()`

Permet d’écrire un certain nombre d’octets.

```cpp
file.write(reinterpret_cast<char*>(&value), sizeof(value));
```

### `read()`

Permet de lire un certain nombre d’octets.

```cpp
file.read(reinterpret_cast<char*>(&value), sizeof(value));
```

### Ce qu’il faut comprendre

- `reinterpret_cast<char*>` sert à voir l’adresse mémoire comme une suite d’octets.
- `sizeof(value)` indique combien d’octets doivent être transférés.

---

## 14. Texte vs binaire

### Format texte

Avantages :

- lisible par un humain,
- facile à déboguer,
- pratique pour CSV, logs, config, fichiers simples.

Inconvénients :

- parfois plus volumineux,
- plus lent à parser,
- perte possible de fidélité selon le formatage.

### Format binaire

Avantages :

- souvent plus compact,
- parfois plus rapide,
- proche de la mémoire.

Inconvénients :

- non lisible directement,
- dépendances possibles à la représentation mémoire,
- plus délicat à rendre portable.

---

## 15. Précautions avec le binaire

Il faut être prudent : écrire directement un objet complexe en binaire n’est pas toujours sûr.

Exemple de pièges :

- différences d’architecture,
- padding mémoire,
- endianness,
- objets contenant des pointeurs,
- classes complexes avec gestion dynamique.

Pour débuter, le mode binaire est surtout simple avec :

- des types primitifs (`int`, `double`, etc.),
- des structures simples soigneusement conçues.

---

## 16. États d’un flux

Un flux peut entrer dans plusieurs états :

- **bon état** : tout se passe bien,
- **fin de fichier**,
- **échec de lecture**,
- **erreur grave**.

C’est pour cela qu’on voit souvent :

```cpp
while (file >> value) {
    // lecture valide
}
```

La boucle s’arrête automatiquement quand la lecture ne peut plus continuer.

C’est une bonne pratique, plus robuste qu’une boucle basée seulement sur `eof()`.

---

## 17. Pourquoi `while (!file.eof())` est souvent déconseillé

Un piège classique en C++ est d’écrire :

```cpp
while (!file.eof()) {
    file >> value;
}
```

Le problème est que `eof()` ne devient vrai **qu’après** une tentative de lecture ratée en fin de fichier.

On peut donc faire une itération de trop ou traiter des données invalides.

La forme recommandée reste :

```cpp
while (file >> value) {
    // utiliser value
}
```

ou :

```cpp
while (std::getline(file, line)) {
    // utiliser line
}
```

---

## 18. Exemples d’usage concrets

Cette vidéo peut être reliée à des situations très concrètes.

### Sauvegarder des résultats

```cpp
std::ofstream result("scores.txt");
result << "Alice 12\n";
result << "Bob 9\n";
```

### Lire une configuration simple

```cpp
std::ifstream cfg("config.txt");
std::string key;
int value;
```

### Ajouter des logs

```cpp
std::ofstream log("program.log", std::ios::app);
log << "Programme lancé\n";
```

### Sauvegarder des données brutes

```cpp
double x = 3.14;
std::ofstream f("x.bin", std::ios::binary);
f.write(reinterpret_cast<char*>(&x), sizeof(x));
```

---

## 19. Schéma mental à retenir

Quand tu travailles avec des fichiers en C++, pense à la séquence suivante :

1. inclure `<fstream>` ;
2. choisir le bon type de flux (`ifstream`, `ofstream`, `fstream`) ;
3. ouvrir le fichier ;
4. vérifier que l’ouverture a réussi ;
5. lire ou écrire ;
6. fermer le fichier si nécessaire.

---

## 20. Exemple complet — écriture texte

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream file("message.txt");

    if (!file) {
        std::cout << "Impossible d'ouvrir le fichier\n";
        return 1;
    }

    file << "Bonjour" << std::endl;
    file << "Ceci est un test." << std::endl;

    file.close();
    return 0;
}
```

---

## 21. Exemple complet — lecture ligne par ligne

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("message.txt");

    if (!file) {
        std::cout << "Impossible d'ouvrir le fichier\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}
```

---

## 22. Exemple complet — écriture et lecture binaire

```cpp
#include <iostream>
#include <fstream>

int main() {
    int number = 42;

    {
        std::ofstream out("number.bin", std::ios::binary);
        if (!out) {
            std::cout << "Erreur ouverture écriture\n";
            return 1;
        }
        out.write(reinterpret_cast<char*>(&number), sizeof(number));
    }

    int loaded = 0;

    {
        std::ifstream in("number.bin", std::ios::binary);
        if (!in) {
            std::cout << "Erreur ouverture lecture\n";
            return 1;
        }
        in.read(reinterpret_cast<char*>(&loaded), sizeof(loaded));
    }

    std::cout << "Valeur relue : " << loaded << std::endl;
    return 0;
}
```

---

## 23. Erreurs fréquentes de débutant

### Oublier `#include <fstream>`

Sans cela, les classes de fichiers ne sont pas connues.

### Ne pas vérifier l’ouverture

Le programme peut sembler correct, mais ne rien lire ou écrire.

### Confondre texte et binaire

`<<` / `>>` ne servent pas au même usage que `write()` / `read()`.

### Écraser un fichier sans le vouloir

Il faut penser à `std::ios::app` quand on veut conserver l’ancien contenu.

### Mal utiliser `eof()`

Préférer une boucle basée sur la réussite effective de la lecture.

### Lire avec `>>` alors qu’on veut une ligne entière

Dans ce cas, il faut plutôt `getline()`.

---

## 24. Ce qu’il faut vraiment maîtriser après cette vidéo

À la fin, tu dois être capable de :

- expliquer ce qu’est un flux,
- distinguer `ifstream`, `ofstream` et `fstream`,
- ouvrir un fichier texte en lecture ou écriture,
- vérifier si l’ouverture a réussi,
- écrire avec `<<`,
- lire avec `>>` et `getline()`,
- comprendre la différence entre écrasement et ajout,
- expliquer à quoi sert `std::ios::binary`,
- utiliser `read()` et `write()` pour des données binaires simples.

---

## 25. Exercice de fin de vidéo

### Énoncé

Écris un programme C++ qui gère un petit fichier de notes d’étudiants.

Le programme doit :

1. créer ou ouvrir un fichier texte `notes.txt` en mode ajout ;
2. demander à l’utilisateur de saisir :
   - un nom,
   - une note sur 20 ;
3. enregistrer ces informations dans le fichier sur une ligne du type :

```text
Alice 14.5
```

4. rouvrir ensuite le fichier en lecture ;
5. afficher tout son contenu ligne par ligne ;
6. compter combien de lignes sont présentes dans le fichier et afficher ce nombre.

### Contraintes pédagogiques

Ton programme doit obligatoirement utiliser :

- `std::ofstream`,
- `std::ifstream`,
- `std::ios::app`,
- `std::getline()` ou une lecture adaptée,
- une vérification d’ouverture de fichier.

### Ce que cet exercice t’apprend

- la différence entre écriture et lecture,
- l’intérêt du mode ajout,
- le parcours d’un fichier ligne par ligne,
- l’usage concret des flux de fichiers en C++.

### Variante un peu plus avancée

Fais une seconde version où tu sauvegardes seulement un entier en **binaire**, puis tu le relis et l’affiches.

---

## 26. Résumé ultra synthétique

- `<fstream>` permet de manipuler les fichiers en C++.
- `ofstream` écrit, `ifstream` lit, `fstream` fait les deux.
- `<<` et `>>` servent surtout au texte.
- `getline()` lit une ligne entière.
- `std::ios::app` ajoute à la fin.
- `std::ios::binary` active le mode binaire.
- `write()` et `read()` servent pour les octets bruts.
- Il faut toujours vérifier que le fichier est bien ouvert.

