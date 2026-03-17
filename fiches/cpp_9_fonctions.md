Salut à tous ! Bienvenue pour cette neuvième séance. Aujourd'hui, on franchit une étape cruciale : on va apprendre à **factoriser notre code** grâce aux **fonctions**.

À mesure que vos projets grandissent, vous ne pouvez pas tout écrire à la suite dans le `main`. On va isoler des blocs d'algorithmes pour les réutiliser facilement, ce qui rendra votre code plus propre, plus lisible et surtout plus facile à maintenir. Allez, on passe sur l'éditeur !

---

### 1. Structure d'une fonction [[04:20](http://www.youtube.com/watch?v=2CzOycVN-FY&t=260)]

Une fonction, c'est comme une petite machine : vous lui donnez (éventuellement) des ingrédients en entrée, elle fait sa cuisine, et elle vous rend (éventuellement) un résultat.

```cpp
// Type de retour | Nom | (Paramètres)
int somme(int a, int b) {
    return a + b; // On renvoie le résultat [00:10:20]
}

// Si la fonction ne renvoie RIEN, on utilise 'void' [00:06:33]
void direBonjour() {
    std::cout << "Salut tout le monde !" << std::endl;
}

```

**Vocabulaire technique :**

* **Paramètres** : Les variables définies dans la signature de la fonction (ex: `int a`). [[08:08](http://www.youtube.com/watch?v=2CzOycVN-FY&t=488)]
* **Arguments** : Les valeurs réelles envoyées lors de l'appel (ex: `somme(14, 7)`). [[08:14](http://www.youtube.com/watch?v=2CzOycVN-FY&t=494)]

---

### 2. Passage par Valeur vs Passage par Référence [[15:43](http://www.youtube.com/watch?v=2CzOycVN-FY&t=943)]

C'est là que beaucoup de gens bloquent. Soyez attentifs !

* **Par Valeur (Copie)** : Le compilateur crée une copie de votre variable. Si vous modifiez la variable dans la fonction, l'originale à l'extérieur ne change pas. [[17:03](http://www.youtube.com/watch?v=2CzOycVN-FY&t=1023)]
* **Par Référence (`&`)** : Vous passez un **alias** (un surnom) de votre variable originale. Toute modification à l'intérieur impacte directement l'extérieur ! [[18:27](http://www.youtube.com/watch?v=2CzOycVN-FY&t=1107)]

```cpp
void modifier(int &n) { // Le '&' indique une référence [00:23:23]
    n += 10;
}

int main() {
    int score {50};
    modifier(score); 
    // score vaut maintenant 60 !
}

```

---

### 3. La Surcharge de fonction (Overloading) [[24:49](http://www.youtube.com/watch?v=2CzOycVN-FY&t=1489)]

En C++, vous pouvez avoir plusieurs fonctions avec le **même nom**, à condition que leurs paramètres soient différents (en type ou en nombre).

```cpp
void afficher(int n);
void afficher(double d);
void afficher(std::string s);

```

*Note : Le type de retour n'est pas pris en compte pour différencier les fonctions surchargées.* [[27:51](http://www.youtube.com/watch?v=2CzOycVN-FY&t=1671)]

---

### 4. Les Expressions Lambda (Fonctions anonymes) [[29:12](http://www.youtube.com/watch?v=2CzOycVN-FY&t=1752)]

C'est une syntaxe un peu plus moderne (et déroutante au début) pour créer des fonctions locales très courtes.

```cpp
auto hello = []() { // [] est la zone de capture [00:30:24]
    std::cout << "Hello Lambda !" << std::endl;
};

hello(); // Appel de la fonction

```

**La zone de capture `[ ]` [[33:39](http://www.youtube.com/watch?v=2CzOycVN-FY&t=2019)] :**

* `[=]` : On capture toutes les variables locales par **copie**.
* `[&]` : On capture tout par **référence**.
* `[n]` : On capture uniquement la variable `n`.

---

### Fiche Mémoire Express 📝

| Concept | Syntaxe | Rôle |
| --- | --- | --- |
| **Déclaration** | `type nom(params) { ... }` | Définit le comportement. |
| **`return`** | `return valeur;` | Sort de la fonction et renvoie un résultat. |
| **`void`** | `void maFonction()` | Indique que la fonction ne renvoie rien. |
| **Référence** | `void f(int &x)` | Modifie directement la variable d'origine. |
| **Lambda** | `[](params){ code }` | Fonction anonyme définie localement. |

**Votre mission :** Créez une fonction qui calcule la moyenne de deux notes. Essayez ensuite de passer ces notes par référence pour les remettre à zéro après le calcul. Observez bien la portée de vos variables ! [[42:00](http://www.youtube.com/watch?v=2CzOycVN-FY&t=2520)]

Si vous avez des questions sur les passages par référence ou la syntaxe des lambdas, direction les commentaires. Prochaine étape : on va voir comment découper tout ça dans **plusieurs fichiers**. À bientôt ! [[43:05](http://www.youtube.com/watch?v=2CzOycVN-FY&t=2585)]