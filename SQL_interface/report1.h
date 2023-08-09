#ifndef REPORT1_H
#define REPORT1_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>

namespace Ui {
class report1;
}

class report1 : public QWidget
{
    Q_OBJECT

public:
    explicit report1(QWidget *parent = nullptr);
    ~report1();

private:
    Ui::report1 *ui;
    QSqlQueryModel *quore;
    QSqlQueryModel *quore1;
public slots:
    void report1_sl();
private slots:
    void on_pushButton_clicked();
};

#endif // REPORT1_H
