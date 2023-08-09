#include "report1.h"
#include "ui_report1.h"

report1::report1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report1)
{
    ui->setupUi(this);
    quore=new QSqlQueryModel;
    quore1=new QSqlQueryModel;
}

report1::~report1()
{
    delete ui;
}

void report1::report1_sl()
{
    this->show();
    QString text=" ALTER TABLE truck_summary"
                 " ADD por int,"
                 " add polez int;"
                 " update truck_summary"
                 " set por=1,polez=1; "
                 " create table a"
                 " select truck_summary.truck_id, truck_summary.por, truck_summary.polez, flight.cargo_type,"
                 " flight.date_start, flight.date_finish  from truck_summary inner join flight"
                 " on truck_summary.truck_id=flight.truck_id;"
                 " update a set por=if(cargo_type=1,por,datediff(date_finish,date_start)*por),"
                   " polez=if(cargo_type=0, polez,datediff(date_finish,date_start)*polez);";
    quore->setQuery(text);
    quore->setQuery(" select truck_id, sum(por)/sum(polez)"
                        " from a"
                    " group by truck_id;");


     quore1->setQuery("create table b select truck_id, sum(por)/sum(polez) as cr from a group by truck_id;");

     QString text2="select avg(cr) from b;";

    ui->tableView->setModel(quore);
    quore1->setQuery(text2);
    ui->tableView_2->setModel(quore1);
}



void report1::on_pushButton_clicked()
{
    quore->setQuery(" drop table b; drop table a; ALTER TABLE truck_summary DROP COLUMN polez; ALTER TABLE truck_summary DROP COLUMN por;");
    this->close();
}

