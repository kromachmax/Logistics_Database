#ifndef REPORT4_H
#define REPORT4_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>

namespace Ui {
class report4;
}

class report4 : public QWidget
{
    Q_OBJECT

public:
    explicit report4(QWidget *parent = nullptr);
    ~report4();

private:
    Ui::report4 *ui;
    QSqlQueryModel *quore;
    QSqlQueryModel *quore1;
public slots:
    void report4_sl();
};

#endif // REPORT4_H
