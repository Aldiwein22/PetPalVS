#include "Pet.h"

Pet::Pet(const QString &name, const QString &species)
    : name(name), species(species), hunger(100), happiness(100), health(100) {}

QString Pet::getName() const {
    return name;
}

QString Pet::getSpecies() const {
    return species;
}

int Pet::getHunger() const {
    return hunger;
}

int Pet::getHappiness() const {
    return happiness;
}

int Pet::getHealth() const {
    return health;
}

void Pet::feed() {
    if (hunger < 100) hunger += 10;
}

void Pet::pet() {
    if (happiness < 100) happiness += 10;
}

void Pet::train() {
    if (health < 100) health += 10;
}

void Pet::saveStatus() {
    // Logik zum Speichern des Zustands
}

void Pet::loadStatus() {
    // Logik zum Laden des Zustands
}

void Pet::updateEmotionalState() {
    // Logik zur Aktualisierung des emotionalen Zustands
}
