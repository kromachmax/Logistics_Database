#include "report5.h"
#include "ui_report5.h"

report5::report5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report5)
{
    ui->setupUi(this);
    quore=new QSqlQueryModel;
    quore1=new QSqlQueryModel;
    quore2=new QSqlQueryModel;
    quore3=new QSqlQueryModel;
    quore4=new QSqlQueryModel;
    quore5=new QSqlQueryModel;
    quore6=new QSqlQueryModel;
}

report5::~report5()
{
    delete ui;
}

void report5::report5_sl()
{
    this->show();

    QString text=" create table new_table2"
                 " select truck.truck_id as truck_id, sum(datediff(flight.date_finish, flight.date_start))*avg(truck.empty_expenses) as sum"
                 " from truck, flight where truck.truck_id=flight.truck_id and flight.cargo_type=0"
                 " group by truck.truck_id;"
                 " create table new_table3"
                 " select truck.truck_id as truck_id,"
                 " (datediff((select max(free_date)from truck), avg(date_of_registration))-sum(datediff(flight.date_finish, flight.date_start)))*avg(truck.downtime_costs) as sum"
                 " from truck, flight where truck.truck_id=flight.truck_id"
                 " group by truck.truck_id;"
                 " create table new_table1"
                 " select truck.truck_id as truck_id, sum(datediff(flight.date_finish, flight.date_start)) *avg(truck.freight_charges) as sum"
                 " from truck, flight where truck.truck_id=flight.truck_id and flight.cargo_type=1"
                 " group by truck.truck_id;"
                 " create table new_table4"
                 " select cargo_type.cargo_type_id, orders.cargo_type, sum(volume) as volume, avg(cargo_type.price) as price, sum(volume*cargo_type.price) as sum"
                 " from orders, cargo_type where orders.cargo_type=cargo_type.cargo_type"
                 " group by cargo_type_id;"
                 " create table new_table5"
                 " select count(*) as Quantity, sum(truck_price) as expenses"
                 " from truck_summary;"
                 " create table new_table6"
                 " select count(*) as Quantity, sum(truck_price) as profit"
                 " from truck_summary"
                 " where date_of_sale!=null; "
                 " set @sum1=(select sum(sum) from new_table1);"
                 " set @sum2=(select sum(sum) from new_table2);"
                 " set @sum3=(select sum(sum) from new_table3);"
                 " set @result=@sum1+@sum2+@sum3;"
                 " set @result2=(select sum(volume*price) from new_table4);"
                 " set @result3=(select sum(expenses) from new_table5);"
                 " set @result4=(select sum(profit) from new_table6);"
                 " set @profit = @result2-@result-@result3;";
    quore->setQuery(text);
    quore->setQuery("create TABLE a select @profit;");
    quore->setQuery("select *from new_table1;");
    quore1->setQuery("select *from new_table2;");
    quore2->setQuery("select *from new_table3;");
    quore3->setQuery("select *from new_table4;");
    quore4->setQuery("select *from new_table5;");
    quore5->setQuery("select *from new_table6;");
    quore6->setQuery("select *from a;");

    ui->prost->setModel(quore2);
    ui->buy->setModel(quore4);
    ui->polez->setModel(quore);
    ui->por->setModel(quore1);
    ui->sale->setModel(quore5);
    ui->tov->setModel(quore3);
    ui->otchet->setModel(quore6);
}

void report5::on_pushButton_clicked()
{
    quore->setQuery(" drop table a; drop table new_table1; drop table new_table2; drop table new_table3;  drop table new_table4; drop table new_table5; drop table new_table6;");
    this->close();
}

