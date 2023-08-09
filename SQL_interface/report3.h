#ifndef REPORT3_H
#define REPORT3_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>

namespace Ui {
class report3;
}

class report3 : public QWidget
{
    Q_OBJECT

public:
    explicit report3(QWidget *parent = nullptr);
    ~report3();

private:
    Ui::report3 *ui;
    QSqlQueryModel *quore;
    QSqlQueryModel *quore1;
public slots:
    void report3_sl();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // REPORT3_H
