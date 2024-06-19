#include "GUI.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

GUI::GUI(QWidget *parent) : QWidget(parent), currentPet(nullptr) {
    stackedWidget = new QStackedWidget(this);
    setupMainMenu();
    setupPetScreen();
    weatherAPI = new WeatherAPI(this);
    connect(weatherAPI, &WeatherAPI::weatherDataReceived, this, &GUI::onWeatherDataReceived);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);
    stackedWidget->setCurrentWidget(mainMenu);
}

GUI::~GUI() {
    delete currentPet;
}

void GUI::setupMainMenu() {
    mainMenu = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainMenu);
    QPushButton *neuesHaustierButton = new QPushButton("Neues Haustier erstellen", mainMenu);
    QPushButton *gespeichertesHaustierButton = new QPushButton("Gespeichertes Haustier laden", mainMenu);
    layout->addWidget(neuesHaustierButton);
    layout->addWidget(gespeichertesHaustierButton);
    connect(neuesHaustierButton, &QPushButton::clicked, this, &GUI::erstelleNeuesHaustier);
    connect(gespeichertesHaustierButton, &QPushButton::clicked, this, &GUI::ladeGespeichertesHaustier);
    stackedWidget->addWidget(mainMenu);
    qDebug() << "MainMenu setup complete.";
}

void GUI::setupPetScreen() {
    petScreen = new QWidget(this);
    QGridLayout *layout = new QGridLayout(petScreen);
    QPushButton *fuetternButton = new QPushButton("Füttern", petScreen);
    QPushButton *streichelnButton = new QPushButton("Streicheln", petScreen);
    QPushButton *trainierenButton = new QPushButton("Trainieren", petScreen);
    QPushButton *speichernButton = new QPushButton("Speichern", petScreen);
    QPushButton *anpassenButton = new QPushButton("Anpassen", petScreen);
    QPushButton *kommunizierenButton = new QPushButton("Kommunizieren", petScreen);
    QPushButton *wetterButton = new QPushButton("Wetter abrufen", petScreen);
    petNameLabel = new QLabel("Name: ", petScreen);
    petSpeciesLabel = new QLabel("Art: ", petScreen);
    petHungerLabel = new QLabel("Hunger: ", petScreen);
    petHappinessLabel = new QLabel("Glücklichkeit: ", petScreen);
    petHealthLabel = new QLabel("Gesundheit: ", petScreen);
    layout->addWidget(petNameLabel, 0, 0, 1, 2);
    layout->addWidget(petSpeciesLabel, 1, 0, 1, 2);
    layout->addWidget(petHungerLabel, 2, 0, 1, 2);
    layout->addWidget(petHappinessLabel, 3, 0, 1, 2);
    layout->addWidget(petHealthLabel, 4, 0, 1, 2);
    layout->addWidget(fuetternButton, 5, 0);
    layout->addWidget(streichelnButton, 5, 1);
    layout->addWidget(trainierenButton, 6, 0);
    layout->addWidget(speichernButton, 6, 1);
    layout->addWidget(anpassenButton, 7, 0);
    layout->addWidget(kommunizierenButton, 7, 1);
    layout->addWidget(wetterButton, 8, 0, 1, 2);
    connect(fuetternButton, &QPushButton::clicked, this, &GUI::fuettern);
    connect(streichelnButton, &QPushButton::clicked, this, &GUI::streicheln);
    connect(trainierenButton, &QPushButton::clicked, this, &GUI::trainieren);
    connect(speichernButton, &QPushButton::clicked, this, &GUI::speichern);
    connect(anpassenButton, &QPushButton::clicked, this, &GUI::anpassen);
    connect(kommunizierenButton, &QPushButton::clicked, this, &GUI::kommunizieren);
    connect(wetterButton, &QPushButton::clicked, [this]() {
        weatherAPI->getWeatherData("Berlin");
    });
    stackedWidget->addWidget(petScreen);
    qDebug() << "PetScreen setup complete.";
}

void GUI::onWeatherDataReceived(const QString &weather) {
    qDebug() << "Aktuelles Wetter: " << weather;
    if (currentPet) {
        currentPet->adjustMoodBasedOnWeather(weather);
        qDebug() << "Stimmung des Haustiers angepasst basierend auf dem Wetter.";
        updatePetStatus();
    }
}

void GUI::erstelleNeuesHaustier() {
    delete currentPet;
    currentPet = new Pet("Fluffy", "Hund");
    qDebug() << "Neues Haustier erstellt.";
    updatePetStatus();
    stackedWidget->setCurrentWidget(petScreen);
    qDebug() << "Switched to petScreen.";
}

void GUI::ladeGespeichertesHaustier() {
    // Logik zum Laden eines gespeicherten Haustiers
    qDebug() << "Gespeichertes Haustier geladen.";
    updatePetStatus();
    stackedWidget->setCurrentWidget(petScreen);
    qDebug() << "Switched to petScreen.";
}

void GUI::fuettern() {
    if (currentPet) {
        currentPet->feed();
        qDebug() << "Haustier gefüttert.";
        updatePetStatus();
    }
}

void GUI::streicheln() {
    if (currentPet) {
        currentPet->pet();
        qDebug() << "Haustier gestreichelt.";
        updatePetStatus();
    }
}

void GUI::trainieren() {
    if (currentPet) {
        currentPet->train();
        qDebug() << "Haustier trainiert.";
        updatePetStatus();
    }
}

void GUI::speichern() {
    if (currentPet) {
        currentPet->saveStatus();
        qDebug() << "Haustierstatus gespeichert.";
    }
}

void GUI::anpassen() {
    // Logik zur Anpassung des Haustiers
    qDebug() << "Haustier angepasst.";
}

void GUI::kommunizieren() {
    // Logik zur Kommunikation mit dem Haustier
    qDebug() << "Mit Haustier kommuniziert.";
}

void GUI::updatePetStatus() {
    if (currentPet) {
        petNameLabel->setText("Name: " + currentPet->getName());
        petSpeciesLabel->setText("Art: " + currentPet->getSpecies());
        petHungerLabel->setText("Hunger: " + QString::number(currentPet->getHunger()));
        petHappinessLabel->setText("Glücklichkeit: " + QString::number(currentPet->getHappiness()));
        petHealthLabel->setText("Gesundheit: " + QString::number(currentPet->getHealth()));
    }
}
