
#include "mainwindow.h"

#include <QApplication>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
