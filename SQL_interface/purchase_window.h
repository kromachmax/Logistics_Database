#ifndef PURCHASE_WINDOW_H
#define PURCHASE_WINDOW_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QErrorMessage>
#include<QIntValidator>


namespace Ui {
class Purchase_window;
}

class Purchase_window : public QWidget
{
    Q_OBJECT

public:
    explicit Purchase_window(QWidget *parent = nullptr);
    ~Purchase_window();

private:
    Ui::Purchase_window *ui;
    QSqlQueryModel * query;
    int capit;
    QErrorMessage *er;
    int x=0;

public slots:
    void open_purchase_w_sl(int value);
    void open_purchase_w_sl2(int value);
private slots:
    void on_addbuttom_clicked();
    void on_closebuttom_clicked();
signals:
    void change_cap(int a);
    void change_cap3(int a);
    void change_cap2(int a);
};


#endif // PURCHASE_WINDOW_H
