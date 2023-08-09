#ifndef REPORT5_H
#define REPORT5_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>

namespace Ui {
class report5;
}

class report5 : public QWidget
{
    Q_OBJECT

public:
    explicit report5(QWidget *parent = nullptr);
    ~report5();

private:
    Ui::report5 *ui;
    QSqlQueryModel *quore;
    QSqlQueryModel *quore1;
    QSqlQueryModel *quore2;
    QSqlQueryModel *quore3;
    QSqlQueryModel *quore4;
    QSqlQueryModel *quore5;
    QSqlQueryModel *quore6;
public slots:
    void report5_sl();
private slots:
    void on_pushButton_clicked();
};

#endif // REPORT5_H
