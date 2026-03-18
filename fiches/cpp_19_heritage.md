## Séance 19 — Héritage et Composition en C++

### C'est quoi l'héritage ?

Un mécanisme qui permet de créer des **relations entre classes** : une classe enfant hérite des attributs et méthodes d'une classe parente, tout en pouvant en ajouter de nouvelles.

**Règle clé :** si on peut dire *"B est une sorte de A"* → relation d'**héritage**.
- Un chat est une sorte d'animal ✅
- Un personnage est une sorte d'unité ✅
- Un bouton est une sorte de widget ✅

---

### Syntaxe de l'héritage

```cpp
// Unit.h — Classe de base (classe mère)
class Unit {
public:
    Unit(int id, std::string name);
    std::string getName() const;
    int getId() const;

private:
    int m_id;
    std::string m_name;
};
```

```cpp
// Character.h — Classe dérivée (classe enfant)
#include "Unit.h"

class Character : public Unit  // "Character est une sorte de Unit"
{
public:
    Character(int id, std::string name, int level);
    int getLevel() const;

    using Unit::Unit; // héritage explicite des constructeurs (obligatoire en C++)

private:
    int m_level;     // attribut supplémentaire propre à Character
};
```

> ⚠️ En C++, les constructeurs **ne sont pas hérités automatiquement**. Il faut l'indiquer explicitement avec `using`.

---

### Appel au constructeur parent

Dans la liste d'initialisation, on appelle le constructeur de la classe mère :

```cpp
// Character.cpp
Character::Character(int id, std::string name, int level)
    : Unit(id, name),   // on délègue id et name au constructeur parent
      m_level(level)    // on initialise ce qui est propre à Character
{}

int Character::getLevel() const {
    return this->m_level;
}
```

```cpp
// main.cpp
Character player(1, "Jean", 5);
std::cout << player.getName();  // hérité de Unit
std::cout << player.getId();    // hérité de Unit
std::cout << player.getLevel(); // propre à Character
```

---

### Héritage vs Composition

Ce sont deux choses **très différentes** :

| | Héritage | Composition |
|---|---|---|
| Relation | "B **est une sorte de** A" | "A **contient** un B" |
| Exemple | `Character : public Unit` | `Quest` possède un `QuestStatus` |
| Syntaxe | `: public NomClasse` | Attribut de type d'une autre classe |

---

### Exemple de Composition

```cpp
// QuestStatus.h
enum class QuestStatus {
    Disabled,
    Active,
    Failed
};
```

```cpp
// Quest.h
#include "QuestStatus.h"
#include "Unit.h"

class Quest {
public:
    Quest(std::string name, std::string description, const Unit& giver);
    void printInfo() const;

private:
    std::string m_name;
    std::string m_description;
    QuestStatus m_status = QuestStatus::Disabled; // composition
};
```

Ici `Quest` n'hérite **pas** de `QuestStatus` — elle en **contient** une instance. C'est de la composition.

---

### Héritage multiple (spécificité du C++)

C++ permet d'hériter de **plusieurs classes à la fois** — ce qui n'existe pas dans tous les langages :

```cpp
class C : public A, public B { ... };
```

> À utiliser avec parcimonie. La plupart des langages utilisent les **interfaces** pour pallier l'absence de cette fonctionnalité.

---

### Exemple complet

```cpp
// main.cpp
#include "Unit.h"
#include "Character.h"
#include "Quest.h"

int main() {
    Unit blacksmith(1, "Forgeron");

    Character player(2, "Jean", 1);
    std::cout << player.getName()  << "\n"; // "Jean"   — hérité de Unit
    std::cout << player.getId()    << "\n"; // 2        — hérité de Unit
    std::cout << player.getLevel() << "\n"; // 1        — propre à Character

    Quest quest("Tuer des sangliers",
                "Ramener 10 peaux de sanglier au forgeron.",
                blacksmith);
    quest.printInfo();
}
```

---

### À retenir

- L'héritage n'est **pas systématique** — une classe peut très bien être isolée.
- Ne pas confondre **héritage** (`est une sorte de`) et **composition** (`contient`).
- Le constructeur parent doit être **appelé explicitement** dans la liste d'initialisation.
- Les constructeurs ne sont **pas hérités automatiquement** en C++ → `using Parent::Parent;`
- La prochaine séance abordera le **polymorphisme**, qui est fortement lié à l'héritage.