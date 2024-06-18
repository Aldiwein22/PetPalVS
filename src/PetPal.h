#pragma once
#include "ui_PetPal.h"
#include <QMainWindow>

class PetPal : public QMainWindow {
    Q_OBJECT
    
public:
    PetPal(QWidget* parent = nullptr);
    ~PetPal();

private:
    Ui_PetPal* ui;
};