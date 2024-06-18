#include "PetPal.h"

PetPal::PetPal(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_PetPal)
{
    ui->setupUi(this);
}

PetPal::~PetPal()
{
    delete ui; 
}