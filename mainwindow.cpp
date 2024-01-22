
#include "./ui_mainwindow.h"
#include "dialog.h"
#include "mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString pm = "/Users/janponiatowski/Desktop/Projekty/Dziennik_elektroniczny/kopernik.png";
    ui->logo_szkoly->setPixmap(pm);
    ui->logo_szkoly->setScaledContents(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::printList()
{
    int rowPosition = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(ListaUczniow.size());
    ui->tableWidget->setItem(rowPosition, 0, new QTableWidgetItem(uczen.imie));
    ui->tableWidget->setItem(rowPosition, 1, new QTableWidgetItem(uczen.nazwisko));
    ui->tableWidget->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(uczen.OcenaMatematyka)));
    ui->tableWidget->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(uczen.OcenaPolski)));
    ui->tableWidget->sortItems(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    m_okno = new Dialog(nullptr);
    int result = m_okno->exec();

   if(result)
    {
        QString temp = m_okno->getImie();
       uczen.imie = temp;
        temp = m_okno->getNazwisko();
       uczen.nazwisko = temp;
        int tempint = m_okno->getOcenaMat();
       uczen.OcenaMatematyka = tempint;
        tempint = m_okno->getOcenaPol();
       uczen.OcenaPolski = tempint;
        ListaUczniow.push_back(uczen);
       //sort();
       printList();
        qDebug() << "rozmiar listy: " << ListaUczniow.size();
    }

   delete m_okno;
}


void MainWindow::on_sredniaMatematyka_clicked()
{
    double sredniaOcen = 0;
    iter = ListaUczniow.begin();
    for(int i = 0; i < ListaUczniow.size(); i++)
    {
        sredniaOcen = sredniaOcen + iter->OcenaMatematyka;
        iter++;
    }
    qDebug() << sredniaOcen;
    sredniaOcen = sredniaOcen / (double)ListaUczniow.size();
    ui->srednia_klasy_mat->setText(QString::number(sredniaOcen));
}


void MainWindow::on_sredniaPolski_clicked()
{
    double sredniaOcen = 0;
    iter = ListaUczniow.begin();
    for(int i = 0; i < ListaUczniow.size(); i++)
    {
        sredniaOcen = sredniaOcen + iter->OcenaPolski;
        iter++;
    }
    qDebug() << sredniaOcen;
    sredniaOcen = sredniaOcen / (double)ListaUczniow.size();
    ui->srednia_klasy_2->setText(QString::number(sredniaOcen));
}

