Salut à tous ! Bienvenue pour cette sixième séance. Aujourd'hui, on va parler d'un sujet souvent négligé mais absolument capital : les **opérateurs**.

C'est la base de tous vos calculs et de la logique de vos futurs programmes. Si vous maîtrisez ça, vous éviterez 90% des bugs de logique plus tard. Allez, on passe sur le code !

---

### 1. Les Opérateurs Arithmétiques [[02:39](http://www.youtube.com/watch?v=CZ03XvQySsY&t=159)]

Ce sont les opérateurs classiques pour les calculs mathématiques. Rien de sorcier, mais attention aux priorités !

```cpp
int a {10};
int b {3};

int somme = a + b;       // Addition (13)
int diff  = a - b;       // Soustraction (7)
int prod  = a * b;       // Multiplication (30)
int div   = a / b;       // Division entière (3 car ce sont des int) [00:03:08]
int reste = a % b;       // Modulo : reste de la division (1) [00:03:10]

```

**Règle d'or :** Comme à l'école, la multiplication et la division sont prioritaires sur l'addition. Utilisez des **parenthèses** `( )` pour changer cet ordre ou simplement pour rendre votre code plus lisible ! [[06:55](http://www.youtube.com/watch?v=CZ03XvQySsY&t=415)]

---

### 2. Les Opérateurs de Comparaison [[11:27](http://www.youtube.com/watch?v=CZ03XvQySsY&t=687)]

Ils permettent de comparer deux valeurs. Le résultat est toujours un **booléen** (`true` ou `false`).

```cpp
bool test;
test = (5 == 5);  // Égalité (attention : double égal ==) [00:13:02]
test = (5 != 9);  // Différence (vrai ici) [00:14:26]
test = (5 < 9);   // Inférieur strict [00:12:05]
test = (5 <= 5);  // Inférieur ou égal [00:12:43]

```

---

### 3. Les Opérateurs Booléens (Logique) [[07:35](http://www.youtube.com/watch?v=CZ03XvQySsY&t=455)]

C'est l'algèbre de Boole. On s'en sert pour combiner plusieurs conditions.

* **`!` (NOT)** : Inverse la valeur (Vrai devient Faux). [[08:35](http://www.youtube.com/watch?v=CZ03XvQySsY&t=515)]
* **`&&` (AND)** : Vrai seulement si les DEUX côtés sont vrais. [[08:40](http://www.youtube.com/watch?v=CZ03XvQySsY&t=520)]
* **`||` (OR)** : Vrai si AU MOINS UN des deux côtés est vrai. [[08:44](http://www.youtube.com/watch?v=CZ03XvQySsY&t=524)]

---

### 4. Incrémentation et Raccourcis [[14:55](http://www.youtube.com/watch?v=CZ03XvQySsY&t=895)]

En programmation, on passe notre temps à ajouter 1 à une variable. On a donc des notations raccourcies super pratiques.

```cpp
int score {10};

score += 5;  // Équivaut à : score = score + 5; (15) [00:18:13]
score *= 2;  // Équivaut à : score = score * 2; (30) [00:19:08]

// Incrémentation de 1 [00:20:30]
score++;     // Ajoute 1 (31)
score--;     // Retire 1 (30)

```

**Le piège : Pré-incrémentation vs Post-incrémentation [[23:30](http://www.youtube.com/watch?v=CZ03XvQySsY&t=1410)]**

* `++i` (Pré) : On ajoute 1, **puis** on utilise la valeur.
* `i++` (Post) : On utilise la valeur, **puis** on ajoute 1.
*Conseil : Utilisez la pré-incrémentation (`++i`) par défaut, c'est souvent plus sûr et parfois plus rapide.* [[26:38](http://www.youtube.com/watch?v=CZ03XvQySsY&t=1598)]

---

### Fiche Mémoire Express 📝

| Opérateur | Rôle | Exemple |
| --- | --- | --- |
| `+`, `-`, `*`, `/` | Calculs de base | `a + b` |
| `%` | Reste de division | `10 % 3 = 1` |
| `==` | Test d'égalité | `if (a == b)` |
| `!=` | Test de différence | `if (a != b)` |
| `&&`, ` |  | ` |
| `++`, `--` | Ajouter / Retirer 1 | `compteur++` |
| `+=`, `-=` | Calcul + Affectation | `vie -= 10` |

**Votre mission :** Amusez-vous à créer des expressions complexes avec des parenthèses et des modulos. C'est le meilleur moyen de comprendre comment l'ordinateur réfléchit.

Si vous avez des questions, notamment sur le modulo ou la logique booléenne, n'hésitez pas, les commentaires sont là pour ça ! La prochaine fois, on commence les **structures de contrôle** pour donner une "intelligence" à nos programmes. À bientôt ! [[28:12](http://www.youtube.com/watch?v=CZ03XvQySsY&t=1692)]