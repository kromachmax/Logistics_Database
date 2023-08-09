#ifndef REPORT2_H
#define REPORT2_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>

namespace Ui {
class report2;
}

class report2 : public QWidget
{
    Q_OBJECT

public:
    explicit report2(QWidget *parent = nullptr);
    ~report2();

private:
    Ui::report2 *ui;
    QSqlQueryModel *quore;
    QSqlQueryModel *quore1;

public slots:
    void report2_sl();
private slots:
    void on_pushButton_clicked();
};

#endif // REPORT2_H
