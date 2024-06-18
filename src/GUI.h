#ifndef GUI_H
#define GUI_H

#include <QWidget>

class GUI : public QWidget {
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

    void zeigeHaustierStatus(const class Haustier& haustier);
    void zeigeHauptbildschirm();
    void zeigeAnpassungsbildschirm();
    void zeigeTrainingsbildschirm();
    void zeigeKommunikationsbildschirm();

private slots:
    void erstelleNeuesHaustier();
    void ladeGespeichertesHaustier();
    void fuettern();
    void streicheln();
    void trainieren();
    void speichern();
    void anpassen();
    void kommunizieren();
};

#endif // GUI_H
