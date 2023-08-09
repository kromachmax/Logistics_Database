#include "purchase_window.h"
#include "ui_purchase_window.h"

Purchase_window::Purchase_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Purchase_window)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    query =new QSqlQueryModel;
    er=new QErrorMessage(this);
    er->setModal(true);
    er->resize(500,100);
}

Purchase_window::~Purchase_window()
{
    delete ui;
}

void Purchase_window::open_purchase_w_sl(int value)
{
    capit=value;
    QString Text;


    QString sql = QString(" create table new_table1"
                          " select truck.truck_id as truck_id, sum(datediff(flight.date_finish, flight.date_start)) *avg(truck.freight_charges) as sum"
                          " from truck, flight where truck.truck_id=flight.truck_id and flight.cargo_type=1"
                          " and flight.flight_id > '%1'"
                          " group by truck.truck_id;").arg(x);


    query->setQuery(sql);

    sql = QString("create table new_table2"
                  " select truck.truck_id as truck_id, sum(datediff(flight.date_finish, flight.date_start))*avg(truck.empty_expenses) as sum"
                  " from truck, flight where truck.truck_id=flight.truck_id and flight.cargo_type=0"
                  " and flight.flight_id > '%1' "
                  " group by truck.truck_id;").arg(x);

    query->setQuery(sql);

    sql = QString("create table new_table3"
                  " select truck.truck_id as truck_id, "
                  " (datediff((select max(free_date)from truck), avg(date_of_registration))-sum(datediff(flight.date_finish, flight.date_start)))*avg(truck.downtime_costs) as sum"
                  " from truck, flight where truck.truck_id=flight.truck_id and flight.flight_id > '%1' "
                  " group by truck.truck_id;").arg(x);

    query->setQuery(sql);

    Text="set @sum1=(select sum(sum) from new_table1);"
           " set @sum2=(select sum(sum) from new_table2);"
           " set @sum3=(select sum(sum) from new_table3);"
           " set @result=@sum1+@sum2+@sum3;drop table new_table1;drop table new_table2;drop table new_table3;";


    query->setQuery(Text);

    Text= " create table new_table4"
          " select cargo_type.cargo_type_id, orders.cargo_type, volume, cargo_type.price "
          " from orders, cargo_type where orders.cargo_type=cargo_type.cargo_type;"
          " set @result2=(select sum(volume*price) from new_table4); drop table new_table4;";

    query->setQuery(Text);

    query->setQuery("select @result;");
    int x1 = query->data(query->index(0,0)).toInt();
    capit=capit-x1;

    emit change_cap(x1);


    query->setQuery("select @result2;");
    int x2 = query->data(query->index(0,0)).toInt();
    capit=capit+x2;

    emit change_cap2(x2);

    query->setQuery("select * from flight;");
    x=query->rowCount();
    emit change_cap3(x);

}
void Purchase_window::open_purchase_w_sl2(int value)
{
    this->show();
    x=value;
}

void Purchase_window::on_addbuttom_clicked()
{

    QString Text;
    if(capit < ui->price_edit->text().toInt()){
        er->showMessage("У нас недостаточно средств!");
        ui->lineEdit->clear();
        ui->capacity_edit->clear();
        ui->cargo_type->clear();
        ui->price_edit->clear();
        ui->cityedit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();

    }
    else{
        query->setQuery("select * from truck;");
        int x = query->rowCount();
        if(x==0){
            Text = "insert into truck (load_capacity, truck_price, downtime_costs, freight_charges, empty_expenses,"
                   " cargo_type_id, city_id, free_date, date_of_registration, date_of_sale, besp_prob,prost) values("
                   + ui->capacity_edit->text() + ", " + ui->price_edit->text() + ", " + ui->lineEdit->text() +
                   ", " + ui->lineEdit_3->text() + ", " + ui->lineEdit_2->text() + ", (select cargo_type_id "
                   " from cargo_type where cargo_type = '"
                   + ui->cargo_type->text() + "') , (select city_id "
                   " from city where name_city = '" + ui->cityedit->text() + "'), '2020-01-01', '2020-01-01', null, 1, 1);";
            query->setQuery(Text);
            emit change_cap(ui->price_edit->text().toInt());

            Text="insert into truck_summary(load_capacity, truck_price, downtime_costs, freight_charges, empty_expenses,"
                 "cargo_type, date_of_registration, date_of_sale) values( "
                 + ui->capacity_edit->text() + ", " + ui->price_edit->text() + ", " + ui->lineEdit->text() +
                   ", " + ui->lineEdit_3->text() + ", " + ui->lineEdit_2->text() + ", '" + ui->cargo_type->text() + "', '2020-01-01', null); ";
             query->setQuery(Text);

        }
        else{


            Text ="set @max=(select max(free_date) from truck);"
                   "insert into truck (load_capacity, truck_price, downtime_costs, freight_charges, empty_expenses,"
                   " cargo_type_id, city_id, free_date, date_of_registration, date_of_sale, besp_prob,prost) values("
                   + ui->capacity_edit->text() + ", " + ui->price_edit->text() + ", " + ui->lineEdit->text() +
                   ", " + ui->lineEdit_3->text() + ", " + ui->lineEdit_2->text() + ", (select cargo_type_id "
                   " from cargo_type where cargo_type = '"
                   + ui->cargo_type->text() + "') , (select city_id "
                   " from city where name_city = '" + ui->cityedit->text() + "'), @max, @max, null, 1, 1);";
            query->setQuery(Text);
            emit change_cap(ui->price_edit->text().toInt());


            Text="insert into truck_summary(load_capacity, truck_price, downtime_costs, freight_charges, empty_expenses,"
                   "cargo_type, date_of_registration, date_of_sale) values( "
                   + ui->capacity_edit->text() + ", " + ui->price_edit->text() + ", " + ui->lineEdit->text() +
                   ", " + ui->lineEdit_3->text() + ", " + ui->lineEdit_2->text() + ", '" + ui->cargo_type->text() + "', @max    , null); ";
            query->setQuery(Text);
        }
    }
    ui->lineEdit->clear();
    ui->capacity_edit->clear();
    ui->cargo_type->clear();
    ui->price_edit->clear();
    ui->cityedit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();


}


void Purchase_window::on_closebuttom_clicked()
{
    this->close();
    query->setQuery("drop table a; drop table b; drop table c;");
}
