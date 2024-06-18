#include "GUI.h"
#include "Haustier.h"
#include <QVBoxLayout>
#include <QPushButton>

GUI::GUI(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *neuesHaustierButton = new QPushButton("Neues Haustier erstellen", this);
    QPushButton *gespeichertesHaustierButton = new QPushButton("Gespeichertes Haustier laden", this);
    QPushButton *fuetternButton = new QPushButton("Füttern", this);
    QPushButton *streichelnButton = new QPushButton("Streicheln", this);
    QPushButton *trainierenButton = new QPushButton("Trainieren", this);
    QPushButton *speichernButton = new QPushButton("Speichern", this);
    QPushButton *anpassenButton = new QPushButton("Anpassen", this);
    QPushButton *kommunizierenButton = new QPushButton("Kommunizieren", this);

    layout->addWidget(neuesHaustierButton);
    layout->addWidget(gespeichertesHaustierButton);
    layout->addWidget(fuetternButton);
    layout->addWidget(streichelnButton);
    layout->addWidget(trainierenButton);
    layout->addWidget(speichernButton);
    layout->addWidget(anpassenButton);
    layout->addWidget(kommunizierenButton);

    connect(neuesHaustierButton, &QPushButton::clicked, this, &GUI::erstelleNeuesHaustier);
    connect(gespeichertesHaustierButton, &QPushButton::clicked, this, &GUI::ladeGespeichertesHaustier);
    connect(fuetternButton, &QPushButton::clicked, this, &GUI::fuettern);
    connect(streichelnButton, &QPushButton::clicked, this, &GUI::streicheln);
    connect(trainierenButton, &QPushButton::clicked, this, &GUI::trainieren);
    connect(speichernButton, &QPushButton::clicked, this, &GUI::speichern);
    connect(anpassenButton, &QPushButton::clicked, this, &GUI::anpassen);
    connect(kommunizierenButton, &QPushButton::clicked, this, &GUI::kommunizieren);

    setLayout(layout);
}

GUI::~GUI() {}

void GUI::zeigeHaustierStatus(const Haustier& haustier) {
    // Implementierung der Anzeige des Haustierstatus
}

void GUI::zeigeHauptbildschirm() {
    // Implementierung der Anzeige des Hauptbildschirms
}

void GUI::zeigeAnpassungsbildschirm() {
    // Implementierung der Anzeige des Anpassungsbildschirms
}

void GUI::zeigeTrainingsbildschirm() {
    // Implementierung der Anzeige des Trainingsbildschirms
}

void GUI::zeigeKommunikationsbildschirm() {
    // Implementierung der Anzeige des Kommunikationsbildschirms
}

void GUI::erstelleNeuesHaustier() {
    // Implementierung der Erstellung eines neuen Haustiers
}

void GUI::ladeGespeichertesHaustier() {
    // Implementierung des Ladens eines gespeicherten Haustiers
}

void GUI::fuettern() {
    // Implementierung der Fütterungsfunktion
}

void GUI::streicheln() {
    // Implementierung der Streichelfunktion
}

void GUI::trainieren() {
    // Implementierung der Trainingsfunktion
}

void GUI::speichern() {
    // Implementierung der Speicherfunktion
}

void GUI::anpassen() {
    // Implementierung der Anpassungsfunktion
}

void GUI::kommunizieren() {
    // Implementierung der Kommunikationsfunktion
}
