#ifndef PET_H
#define PET_H

#include <QString>

class Pet {
public:
    Pet(const QString &name, const QString &species);
    QString getName() const;
    QString getSpecies() const;
    int getHunger() const;
    int getHappiness() const;
    int getHealth() const;
    void feed();
    void pet();
    void train();
    void saveStatus();
    void loadStatus(const QString &fileName);
    void updateEmotionalState();
    void adjustMoodBasedOnWeather(const QString &weather);

private:
    QString name;
    QString species;
    int hunger;
    int happiness;
    int health;
    QString currentWeather;
};

#endif // PET_H
