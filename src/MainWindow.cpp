#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = findChild<QStackedWidget*>("stackedWidget");
    mainMenu = findChild<QWidget*>("mainMenu");
    petScreen = findChild<QWidget*>("petScreen");

    gui = new GUI(this);

    connect(findChild<QPushButton*>("newPetButton"), &QPushButton::clicked, this, &MainWindow::on_newPetButton_clicked);
    connect(findChild<QPushButton*>("loadPetButton"), &QPushButton::clicked, this, &MainWindow::on_loadPetButton_clicked);
    connect(findChild<QPushButton*>("fuetternButton"), &QPushButton::clicked, this, &MainWindow::on_fuettern_clicked);
    connect(findChild<QPushButton*>("streichelnButton"), &QPushButton::clicked, this, &MainWindow::on_streicheln_clicked);
    connect(findChild<QPushButton*>("trainierenButton"), &QPushButton::clicked, this, &MainWindow::on_trainieren_clicked);
    connect(findChild<QPushButton*>("speichernButton"), &QPushButton::clicked, this, &MainWindow::on_speichern_clicked);
    connect(findChild<QPushButton*>("anpassenButton"), &QPushButton::clicked, this, &MainWindow::on_anpassen_clicked);
    connect(findChild<QPushButton*>("kommunizierenButton"), &QPushButton::clicked, this, &MainWindow::on_kommunizieren_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gui;
}

void MainWindow::on_newPetButton_clicked()
{
    gui->erstelleNeuesHaustier();
    stackedWidget->setCurrentWidget(petScreen);
}

void MainWindow::on_loadPetButton_clicked()
{
    gui->ladeGespeichertesHaustier();
    stackedWidget->setCurrentWidget(petScreen);
}

void MainWindow::on_fuettern_clicked()
{
    gui->fuettern();
}

void MainWindow::on_streicheln_clicked()
{
    gui->streicheln();
}

void MainWindow::on_trainieren_clicked()
{
    gui->trainieren();
}

void MainWindow::on_speichern_clicked()
{
    gui->speichern();
}

void MainWindow::on_anpassen_clicked()
{
    gui->anpassen();
}

void MainWindow::on_kommunizieren_clicked()
{
    gui->kommunizieren();
}

