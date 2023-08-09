#include "report4.h"
#include "ui_report4.h"

report4::report4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report4)
{
    ui->setupUi(this);
    quore=new QSqlQueryModel;
    quore1=new QSqlQueryModel;
}

report4::~report4()
{
    delete ui;
}

void report4::report4_sl()
{
    this->show();

    QString text="select cargo_type, sum(volume) as popularity from orders group by cargo_type order by popularity desc;";
    quore->setQuery(text);

    ui->tableView->setModel(quore);
}
