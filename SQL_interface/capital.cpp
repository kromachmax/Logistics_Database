#include "capital.h"
#include "ui_capital.h"

capital::capital(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capital)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    ui->lineEdit->setValidator(new QIntValidator);
    er=new QErrorMessage(this);
    er->setModal(true);
    er->resize(500,100);
}

capital::~capital()
{
    delete ui;
}

void capital::capital_sl()
{
    this->show();
}



void capital::on_pushButton_clicked()
{
    int val = ui->lineEdit->text().toInt();
    //qDebug()<<val;


    if(val<=0){
        er->showMessage("Введите корректное значение!");
        ui->lineEdit->clear();
    }
    else{
        emit close_capit(val);
        this->close();
    }
}



