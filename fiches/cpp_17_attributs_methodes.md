## Séance 17 — Attributs et Méthodes en C++

### Vocabulaire

- **Attribut** = une variable déclarée dans une classe
- **Méthode** = une fonction déclarée dans une classe

---

### Constructeur par défaut implicite

Au lieu d'implémenter le constructeur par défaut, on peut demander au compilateur de le générer :

```cpp
// Dans le fichier .h
class Window {
public:
    Window() = default;  // Généré automatiquement par le compilateur
};
```

À l'inverse, `= delete` l'aurait supprimé.

---

### Constructeur enrichi (avec paramètres)

```cpp
// Window.h
#include <string>

class Window {
public:
    Window() = default;
    Window(std::string title, int w = 800, int h = 600); // valeurs par défaut possibles

private:
    std::string m_title;
    int m_width;
    int m_height;
};
```

```cpp
// Window.cpp
Window::Window(std::string title, int w, int h)
    : m_title(title), m_width(w), m_height(h)  // liste d'initialisation
{
    // corps vide ou autre logique
}
```

> ⚠️ Les constructeurs n'ont **pas de type de retour** (même pas `void`).

---

### Liste d'initialisation

C'est la façon recommandée d'initialiser les attributs dans un constructeur :

```cpp
Window::Window(std::string t, int w, int h)
    : m_title(t), m_width(w), m_height(h)
{}
```

Au lieu de faire ça dans le corps :
```cpp
// Moins recommandé
Window::Window(std::string t, int w, int h) {
    m_title = t;
    m_width = w;
    m_height = h;
}
```

---

### `noexcept` — garantie d'absence d'exception

```cpp
Window::Window(int w, int h) noexcept
    : m_width(w), m_height(h)
{}
```

> ⚠️ À n'utiliser que si vous êtes **certain** qu'aucune exception ne sera levée. Avec `std::string`, il y a un risque — donc on **ne met pas** `noexcept`.

---

### Méthode constante

Une méthode qui ne modifie aucun attribut se déclare avec `const` à la fin :

```cpp
// Window.h
void run() const;
```

```cpp
// Window.cpp
void Window::run() const {
    std::cout << "Fenêtre lancée\n";
}
```

Le `const` doit apparaître **à la fois** dans la déclaration et dans l'implémentation.

---

### Appel d'une méthode sur un objet

```cpp
Window w("Mon App", 1280, 720);
w.run(); // appel via l'opérateur point
```

---

### Accès aux attributs privés

```cpp
Window w("Mon App");
w.m_title; // ❌ ERREUR : m_title est privé
```

Les attributs sont en `private` pour respecter l'**encapsulation**. Pour y accéder depuis l'extérieur, il faudra passer par des **getters/setters** — sujet de la prochaine séance.

---

### Résumé de la structure complète

```cpp
// Window.h
#include <string>

class Window {
public:
    Window() = default;
    Window(std::string title, int w = 800, int h = 600);
    void run() const;

private:
    std::string m_title;
    int m_width;
    int m_height;
};
```

```cpp
// Window.cpp
#include "Window.h"
#include <iostream>

Window::Window(std::string title, int w, int h)
    : m_title(title), m_width(w), m_height(h)
{}

void Window::run() const {
    std::cout << "Running: " << m_title << "\n";
}
```

```cpp
// main.cpp
int main() {
    Window w("Mon Application", 1280, 720);
    w.run(); // Running: Mon Application
}
```