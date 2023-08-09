#include "report2.h"
#include "ui_report2.h"

report2::report2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report2)
{
    ui->setupUi(this);
    quore=new QSqlQueryModel;
    quore1=new QSqlQueryModel;
}

report2::~report2()
{
    delete ui;
}


void report2::report2_sl()
{
    this->show();
    QString text=" ALTER TABLE truck_summary"
                 " ADD por int,"
                 " add polez int;"
                 " update truck_summary"
                 " set por=1,polez=1;"
                 " create table a"
                 " select truck_summary.truck_id, truck_summary.por, truck_summary.polez,"
                 " datediff((select max(free_date)from truck), truck_summary.date_of_registration) as prost, flight.cargo_type,"
                 " flight.date_start, flight.date_finish  from truck_summary inner join flight"
                 " on truck_summary.truck_id=flight.truck_id;"
                 " update a set por=if(cargo_type=1,por,datediff(date_finish,date_start)*por),"
                   " polez=if(cargo_type=0, polez,datediff(date_finish,date_start)*polez);";


     quore->setQuery(text);

     quore->setQuery(" select truck_id, (avg(prost)-sum(datediff(date_finish,date_start)))/(sum(por)+sum(polez)) as PROST"
                     " from a"
                     " group by truck_id;");

     quore1->setQuery("create table b select truck_id, (avg(prost)-sum(datediff(date_finish,date_start)))/(sum(por)+sum(polez)) as PROST from a group by truck_id;");


     QString text2="select avg(PROST) from b; ";


    ui->tableView->setModel(quore);
    quore1->setQuery(text2);
    ui->tableView_2->setModel(quore1);
}

void report2::on_pushButton_clicked()

{
    quore->setQuery("drop table b; drop table a; ALTER TABLE truck_summary DROP COLUMN polez; ALTER TABLE truck_summary DROP COLUMN por;");
    this->close();

}

