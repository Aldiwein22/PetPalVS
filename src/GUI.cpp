#include "GUI.h"

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
    mainMenu->resize(800, 600);
    mainMenu->setFixedSize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(mainMenu);

    QPushButton *neuesHaustierButton = new QPushButton("Neues Haustier erstellen, du Neger", mainMenu);

    QPushButton *gespeichertesHaustierButton = new QPushButton("Gespeichertes Haustier laden", mainMenu);

    layout->addWidget(neuesHaustierButton);
    layout->addWidget(gespeichertesHaustierButton);

    connect(neuesHaustierButton, &QPushButton::clicked, this, &GUI::erstelleNeuesHaustier);
    connect(gespeichertesHaustierButton, &QPushButton::clicked, this, &GUI::ladeGespeichertesHaustier);

    stackedWidget->addWidget(mainMenu);
}

void GUI::setupPetScreen() {
    petScreen = new QWidget(this);
    petScreen->resize(800, 600);
    petScreen->setFixedSize(800, 600);

    QGridLayout *layout = new QGridLayout(petScreen);

    petNameLabel = new QLabel("Name: ", petScreen);
    petSpeciesLabel = new QLabel("Art: ", petScreen);
    petHungerLabel = new QLabel("Hunger: ", petScreen);
    petHappinessLabel = new QLabel("Glücklichkeit: ", petScreen);
    petHealthLabel = new QLabel("Gesundheit: ", petScreen);

    QPushButton *wetterButton = new QPushButton("Wetter abrufen", petScreen);

    connect(wetterButton, &QPushButton::clicked, [this]() {
        weatherAPI->getWeatherData("Berlin");
    });

    petScreen->setLayout(layout);
    stackedWidget->addWidget(petScreen);
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
    updatePetStatus();

    stackedWidget->setCurrentWidget(petScreen);
}

void GUI::ladeGespeichertesHaustier() {
    updatePetStatus();

    if(stackedWidget == nullptr) {
        qDebug() << "stackedWidget is not initialized";
        return;
    }

    if(petScreen == nullptr) {
        qDebug() << "petScreen is not initialized";
        
        return;
    }

    if(!stackedWidget->indexOf(petScreen)) {
        qDebug() << "petScreen is not added to stackedWidget";
        return;
    }

    stackedWidget->setCurrentWidget(petScreen);
}

void GUI::fuettern() {
    QMessageBox::information(this, "Füttern", "Haustier gefüttert.");

    if (currentPet) {
        currentPet->feed();
        qDebug() << "Haustier gefüttert.";
        updatePetStatus();
    }
}

void GUI::streicheln() {
    QMessageBox::information(this, "Streicheln", "Haustier gestreichelt.");
    if (currentPet) {
        currentPet->pet();
        qDebug() << "Haustier gestreichelt.";
        updatePetStatus();
    }
}

void GUI::trainieren() {
    QMessageBox::information(this, "Trainieren", "Haustier trainiert.");
    if (currentPet) {
        currentPet->train();
        qDebug() << "Haustier trainiert.";
        updatePetStatus();
    }
}

void GUI::speichern() {
    QMessageBox::information(this, "Speichern", "Haustierstatus gespeichert.");
    if (currentPet) {
        currentPet->saveStatus();
        qDebug() << "Haustierstatus gespeichert.";
    }
}

void GUI::anpassen() {
    QMessageBox::information(this, "Anpassen", "Haustier angepasst.");
}

void GUI::kommunizieren() {
    QMessageBox::information(this, "Kommunizieren", "Haustier kommuniziert.");
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
