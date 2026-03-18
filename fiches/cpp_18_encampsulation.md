## Séance 18 — Encapsulation en C++

### C'est quoi l'encapsulation ?

Ce n'est **pas** juste "masquer des données". C'est **contrôler l'accès** aux attributs d'une classe via des méthodes, tout en cachant l'implémentation à l'utilisateur. On lui expose uniquement une **interface** (des services/fonctionnalités).

---

### Accesseur (`get`) — lire un attribut

Convention : préfixer par `get` + nom de l'attribut.

```cpp
// Window.h
class Window {
public:
    std::string getTitle() const; // const car pas de modification

private:
    std::string m_title;
};
```

```cpp
// Window.cpp
std::string Window::getTitle() const {
    return this->m_title; // "this->" optionnel mais recommandé pour la clarté
}
```

```cpp
// main.cpp
Window w("Mon App");
std::cout << w.getTitle(); // "Mon App"
```

---

### Modificateur (`set`) — modifier un attribut

Convention : préfixer par `set` + nom de l'attribut.

```cpp
// Window.h
void setTitle(std::string title); // pas const, on modifie !
```

```cpp
// Window.cpp
void Window::setTitle(std::string title) {
    this->m_title = title;
}
```

---

### L'intérêt réel : filtrer / contrôler les données

Le modificateur prend tout son sens quand on ajoute des **vérifications** :

```cpp
void Window::setTitle(std::string title) {
    if (title.length() > 20) {
        throw std::invalid_argument("Titre trop long, 20 caractères maximum");
    }
    this->m_title = title;
}
```

On peut aussi **réutiliser le modificateur dans le constructeur** pour ne pas dupliquer les vérifications :

```cpp
Window::Window(std::string title)
{
    setTitle(title); // les vérifications de setTitle s'appliquent dès la construction
}
```

> ⚠️ Ne faites **pas** de méthode `init()` pour initialiser vos objets — c'est le rôle du **constructeur**.

---

### Les accesseurs ne concernent pas forcément un seul attribut

Un accesseur peut travailler sur **plusieurs attributs** et faire des calculs :

```cpp
class Rectangle {
public:
    int getPerimeter() const { return 2 * m_width + 2 * m_height; }
    int getArea()      const { return m_width * m_height; }

private:
    int m_width;
    int m_height;
};
```

Ici, `m_width` et `m_height` restent privés — on n'expose que ce qui est utile.

---

### ⚠️ Erreur fréquente à éviter

Ne pas créer **automatiquement** un `get` et un `set` pour chaque attribut. Si vous avez 10 attributs, vous n'avez pas forcément besoin de 20 méthodes.

**Bonne pratique :**
- Par défaut, l'attribut est **privé et inaccessible**
- Vous créez un accesseur/modificateur **seulement quand vous en avez besoin**
- Plus il y a de code inutile, plus il y a de risques de bugs

---

### Exemple complet

```cpp
// Window.h
#include <string>

class Window {
public:
    Window(std::string title);
    std::string getTitle() const;
    void setTitle(std::string title);

private:
    std::string m_title;
};
```

```cpp
// Window.cpp
#include "Window.h"
#include <stdexcept>

Window::Window(std::string title) {
    setTitle(title); // réutilise les vérifications du modificateur
}

std::string Window::getTitle() const {
    return this->m_title;
}

void Window::setTitle(std::string title) {
    if (title.length() > 20) {
        throw std::invalid_argument("Titre invalide : 20 caractères maximum");
    }
    this->m_title = title;
}
```

```cpp
// main.cpp
Window w("Mon App");
std::cout << w.getTitle();      // Mon App

w.setTitle("Nouveau titre");
std::cout << w.getTitle();      // Nouveau titre

w.setTitle("Un titre beaucoup trop long !!!"); // ❌ exception levée
```

---

### Résumé

| | Accesseur (`get`) | Modificateur (`set`) |
|---|---|---|
| Rôle | Lire un attribut | Modifier un attribut |
| `const` | ✅ Oui | ❌ Non |
| Retour | Type de l'attribut | `void` (généralement) |
| Contrôle | Rare mais possible | Très utile pour valider |