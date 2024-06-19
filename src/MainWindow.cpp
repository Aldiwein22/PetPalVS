#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newPetButton_clicked()
{
    // Implementiere die Logik für die Erstellung eines neuen Haustiers
}

void MainWindow::on_loadPetButton_clicked()
{
    // Implementiere die Logik für das Laden eines gespeicherten Haustiers
}
