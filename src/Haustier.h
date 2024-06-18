#ifndef HAUSTIER_H
#define HAUSTIER_H

#include <string>

class Haustier {
protected:
    std::string name;
    std::string art;
    int gesundheit;
    int glueck;
    int hunger;

public:
    Haustier(const std::string& name, const std::string& art);
    virtual ~Haustier();

    std::string getName() const;
    std::string getArt() const;
    int getGesundheit() const;
    int getGlueck() const;
    int getHunger() const;

    void fuettern();
    void streicheln();
    virtual void trainieren() = 0;

    void speichereStatus() const;
    void ladeStatus();
    void aktualisiereEmotionalenZustand();
};

#endif // HAUSTIER_H
