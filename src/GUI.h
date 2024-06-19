#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include "WeatherAPI.h"
#include "Pet.h"

class GUI : public QWidget {
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

private slots:
    void onWeatherDataReceived(const QString &weather);  // Methode deklariert
    void erstelleNeuesHaustier();
    void ladeGespeichertesHaustier();
    void fuettern();
    void streicheln();
    void trainieren();
    void speichern();
    void anpassen();
    void kommunizieren();

private:
    void setupMainMenu();
    void setupPetScreen();
    void updatePetStatus();

    WeatherAPI *weatherAPI;
    Pet *currentPet;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QWidget *petScreen;
    QLabel *petNameLabel;
    QLabel *petSpeciesLabel;
    QLabel *petHungerLabel;
    QLabel *petHappinessLabel;
    QLabel *petHealthLabel;
};

#endif // GUI_H
