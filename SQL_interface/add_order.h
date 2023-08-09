#ifndef ADD_ORDER_H
#define ADD_ORDER_H

#include <QWidget>
#include<QSqlTableModel>

namespace Ui {
class add_order;
}

class add_order : public QWidget
{
    Q_OBJECT

public:
    explicit add_order(QWidget *parent = nullptr);
    ~add_order();

private:
    Ui::add_order *ui;
    QSqlQueryModel * query;
public:
    void order_sl();
private slots:
    void on_close_clicked();
    void on_add_clicked();
signals:
    void change_cap(int a);
};

#endif // ADD_ORDER_H
