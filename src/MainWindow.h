#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newPetButton_clicked();
    void on_loadPetButton_clicked();

private:
    Ui::MainWindow *ui;
    void createNewPet();
    void loadPet();
};

#endif // MAINWINDOW_H
