#ifndef DELETE_TRUCK_H
#define DELETE_TRUCK_H

#include <QWidget>
#include<QSqlTableModel>
#include<QSqlQuery>

namespace Ui {
class delete_truck;
}

class delete_truck : public QWidget
{
    Q_OBJECT

public:
    explicit delete_truck(QWidget *parent = nullptr);
    ~delete_truck();

private:
    Ui::delete_truck *ui;
    QSqlQueryModel * query;
    QSqlQueryModel * query2;
public slots:
    void sale_sl();
private slots:
    void on_deletebuttom_clicked();
    void on_closebuttom_clicked();
signals:
    void change_cap2(int a);
};

#endif // DELETE_TRUCK_H
