#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QDialog>
#include "QtWidgets/qtablewidget.h"
#include "dialog.h"

struct NowyUczen
{
    QString imie;
    QString nazwisko;
    int OcenaMatematyka;
    int OcenaPolski;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DodajGracza(QString);
    void printList();

private slots:
    void on_pushButton_4_clicked();

    void on_sredniaMatematyka_clicked();

    void on_sredniaPolski_clicked();

private:
    Ui::MainWindow *ui;
    Dialog* m_okno;
    NowyUczen uczen;
    QList <NowyUczen> ListaUczniow;
    QList <NowyUczen>::iterator iter = ListaUczniow.begin();


};
#endif // MAINWINDOW_H
