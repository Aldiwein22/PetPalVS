#include "Pet.h"
#include <algorithm>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

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

void Pet::loadStatus(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file for reading:" << fileName;
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonObject obj = doc.object();

    name = obj["name"].toString();
    species = obj["species"].toString();
    hunger = obj["hunger"].toInt();
    happiness = obj["happiness"].toInt();
    health = obj["health"].toInt();
}


void Pet::updateEmotionalState() {
    // Logik zur Aktualisierung des emotionalen Zustands
}

void Pet::adjustMoodBasedOnWeather(const QString &weather) {
    currentWeather = weather;
    if (weather == "Rain") {
        happiness = std::max(0, happiness - 10);
    } else if (weather == "Sunny") {
        happiness = std::min(100, happiness + 10);
    }
    // Weitere Wetterbedingungen und deren Auswirkungen auf die Stimmung
}
