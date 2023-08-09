#include "reports.h"
#include "ui_reports.h"

reports::reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reports)
{
    ui->setupUi(this);
    rep1=new report1();
    rep2=new report2();
    rep3=new report3();
    rep4=new report4();
    rep5=new report5();
    connect(this, &reports::report1Sign,rep1,&report1::report1_sl);
    connect(this, &reports::report2Sign,rep2,&report2::report2_sl);
    connect(this, &reports::report3Sign,rep3,&report3::report3_sl);
    connect(this, &reports::report4Sign,rep4,&report4::report4_sl);
    connect(this, &reports::report5Sign,rep5,&report5::report5_sl);
}

reports::~reports()
{
    delete ui;
}

void reports::report_sl()
{
    this->show();
}

void reports::on_buttom1_clicked()
{
    emit report1Sign();
}


void reports::on_buttom2_clicked()
{
    emit report2Sign();
}


void reports::on_buttom3_clicked()
{
    emit report3Sign();
}


void reports::on_buttom4_clicked()
{
    emit report4Sign();
}


void reports::on_buttom5_clicked()
{
    emit report5Sign();
}
