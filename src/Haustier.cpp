#include "Haustier.h"
#include <iostream>
#include <fstream>
#include "include/json.hpp" // Niels Lohmann's JSON Bibliothek

using json = nlohmann::json;

Haustier::Haustier(const std::string& name, const std::string& art)
    : name(name), art(art), gesundheit(100), glueck(100), hunger(0) {}

Haustier::~Haustier() {}

std::string Haustier::getName() const {
    return name;
}

std::string Haustier::getArt() const {
    return art;
}

int Haustier::getGesundheit() const {
    return gesundheit;
}

int Haustier::getGlueck() const {
    return glueck;
}

int Haustier::getHunger() const {
    return hunger;
}

void Haustier::fuettern() {
    hunger = std::max(0, hunger - 10);
    std::cout << name << " wurde gefüttert.\n";
}

void Haustier::streicheln() {
    glueck = std::min(100, glueck + 10);
    std::cout << name << " wurde gestreichelt.\n";
}

void Haustier::speichereStatus() const {
    json status;
    status["gesundheit"] = gesundheit;
    status["glueck"] = glueck;
    status["hunger"] = hunger;

    std::ofstream file(name + ".json");
    file << status.dump(4);
    file.close();
}

void Haustier::ladeStatus() {
    std::ifstream file(name + ".json");
    if (file) {
        json status;
        file >> status;
        gesundheit = status["gesundheit"].get<int>();
        glueck = status["glueck"].get<int>();
        hunger = status["hunger"].get<int>();
    }
    file.close();
}

void Haustier::aktualisiereEmotionalenZustand() {
    // Implementierung der Logik zur Aktualisierung des emotionalen Zustands
}
