
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<purchase_window.h>
#include<delete_truck.h>
#include<add_order.h>
#include<reports.h>
#include<capital.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableselection_activated(int index);

    void on_purchase_buttom_clicked();

    void on_sale_buttom_clicked();

    void on_orderButtom_clicked();

    void on_reportbuttom_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    Purchase_window *pur;
    delete_truck *del;
    add_order * add;
    reports *rep;
    capital *cap;
    int capit;
    int number_of_flights;

    QSqlQueryModel quore;
    QSqlTableModel *dbmodel;
    void capital_start();

signals:
    void open_purchase_w(int value);
    void open_purchase_w2(int value);
    void open_sale();
    void order();
    void report();
    void Capital();
public slots:
    void close_cap_sl(int value);
    void change_cap_sl(int value);
    void change_cap_sl2(int a);
    void change_cap_sl3(int a);
};

#endif // MAINWINDOW_H
