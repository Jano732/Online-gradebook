#include "dialog.h"
#include <QDialog>
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getImie()
{
    return ui->Imie->toPlainText();
}

QString Dialog::getNazwisko()
{
    return ui->Nazwisko->toPlainText();
}

int Dialog::getOcenaMat()
{
    return ui->spinBoxMat->value();
}

int Dialog::getOcenaPol()
{
    return ui->spinBoxPol->value();
}
