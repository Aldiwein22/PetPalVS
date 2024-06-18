#include "PetPal.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PetPal w;
    w.show();
    return a.exec();
}


/*
#include <QApplication>
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GUI gui;
    gui.show();

    return app.exec();
}
*/
