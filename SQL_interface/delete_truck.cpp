#include "delete_truck.h"
#include "ui_delete_truck.h"

delete_truck::delete_truck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_truck)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    query =new QSqlQueryModel;
    query2 =new QSqlQueryModel;
}

delete_truck::~delete_truck()
{
    delete ui;
}
void delete_truck::sale_sl()
{
    this->show();
}

void delete_truck::on_deletebuttom_clicked()
{


    query2->setQuery("select truck_price from truck where truck_id=" + ui->delete_edit->text() + " ;");

    int x1 = query2->data(query2->index(0,0)).toInt();
    QString Text = "delete from truck where truck_id = " + ui->delete_edit->text()+ ";";
    query->setQuery(Text);
    Text = "set @maximum=(select max(free_date) from truck); "
           "update truck_summary set date_of_sale=@maximum where truck_id= " + ui->delete_edit->text()+ ";";
    query->setQuery(Text);
    emit change_cap2(x1);
    ui->delete_edit->clear();
}


void delete_truck::on_closebuttom_clicked()
{
    this->close();
}

