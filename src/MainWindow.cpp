#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_newPetButton_clicked() {
    createNewPet();
}

void MainWindow::on_loadPetButton_clicked() {
    loadPet();
}

void MainWindow::createNewPet() {
    // Hier logik zum Erstellen eines neuen Haustiers implementieren
    QMessageBox::information(this, "Neues Haustier", "Neues Haustier erstellen Funktion ist noch nicht implementiert.");
}

void MainWindow::loadPet() {
    // Hier logik zum Laden eines bestehenden Haustiers implementieren
    QMessageBox::information(this, "Haustier laden", "Haustier laden Funktion ist noch nicht implementiert.");
}
