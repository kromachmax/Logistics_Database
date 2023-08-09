#ifndef CAPITAL_H
#define CAPITAL_H

#include <QDialog>
#include<QErrorMessage>
#include<QIntValidator>

namespace Ui {
class capital;
}

class capital : public QDialog
{
    Q_OBJECT

public:
    explicit capital(QWidget *parent = nullptr);
    ~capital();

private:
    Ui::capital *ui;
    QErrorMessage *er;
public:
    void capital_sl();
private slots:
    void on_pushButton_clicked();
signals:
    void close_capit(int val);
};

#endif // CAPITAL_H
