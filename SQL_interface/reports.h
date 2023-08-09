#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include<report1.h>
#include<report2.h>
#include<report3.h>
#include<report4.h>
#include<report5.h>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>


namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = nullptr);
    ~reports();

private:
    Ui::reports *ui;
    report1 *rep1;
    report2* rep2;
    report3* rep3;
    report4* rep4;
    report5* rep5;
public slots:
    void report_sl();
private slots:
    void on_buttom1_clicked();
    void on_buttom2_clicked();
    void on_buttom3_clicked();
    void on_buttom4_clicked();
    void on_buttom5_clicked();
signals:
    void report1Sign();
    void report2Sign();
    void report3Sign();
    void report4Sign();
    void report5Sign();
};

#endif // REPORTS_H
