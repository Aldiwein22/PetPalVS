#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "GUI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newPetButton_clicked();
    void on_loadPetButton_clicked();
    void on_fuettern_clicked();
    void on_streicheln_clicked();
    void on_trainieren_clicked();
    void on_speichern_clicked();
    void on_anpassen_clicked();
    void on_kommunizieren_clicked();

private:
    Ui::MainWindow *ui;
    GUI *gui;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QWidget *petScreen;
};

#endif // MAINWINDOW_H
