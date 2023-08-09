#include "report3.h"
#include "ui_report3.h"
#include<QFile>
#include<QTextStream>


report3::report3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report3)
{
    ui->setupUi(this);
    quore=new QSqlQueryModel;
    quore1=new QSqlQueryModel;
}

report3::~report3()
{
    delete ui;
}


void report3::report3_sl()
{
    this->show();


}

void report3::on_pushButton_clicked()
{
    quore->setQuery("drop table c; drop table a; drop  table b;");
    this->close();
}


void report3::on_pushButton_2_clicked()
{
    QString text=" create table a"
                   " select city.name_city, orders.cargo_type, sum(orders.volume) as Summa, orders.date_ordering as sdate from city inner join orders"
                   " on city.name_city=orders.start_city"
                   " group by city.name_city, orders.cargo_type, orders.date_ordering;"
                   " create table b"
                   " select city.name_city, orders.cargo_type, sum(orders.volume) as Summa, orders.date_ordering as acdate from city inner join orders"
                   " on city.name_city=orders.finich_city"
                   " group by city.name_city, orders.cargo_type, orders.date_ordering;"
                   " create table c"
                   " select name_city, cargo_type from city cross join cargo_type;"
                   " ALTER TABLE c"
                   " ADD sent int,"
                   " add accepted int;"
                   " update c"
                   " set sent=0,accepted=0;"
                   " update c "
                   " inner join a on a.name_city = c.name_city and c.cargo_type = a.cargo_type"
                   " set c.sent = c.sent + a.Summa where sdate"
                   " BETWEEN '" + ui->Start->text() + "' AND '" + ui->Finish->text() + "';"
                                                                          " update c "
                                                                          " inner join b on b.name_city = c.name_city and c.cargo_type = b.cargo_type"
                                                                          " set c.accepted = c.accepted + b.Summa where acdate "
                                                                          " BETWEEN '" + ui->Start->text() + "' AND '" + ui->Finish->text() + "';";

    quore->setQuery(text);

    quore->setQuery("select* from c");

    ui->tableView->setModel(quore);

    QFile file("myfile.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"File is open";
    }
    QTextStream writeStream(&file);
    writeStream <<"From " << ui->Start->text() << " to " << ui->Finish->text() << "\n";
    writeStream.setFieldWidth(15);
    writeStream          << "name_city\t"  << "cargo_type" << "\t" << "sent" << "\t" << "accepted\n\n";
    quore->setQuery("select * from c");
    int x = quore->rowCount(), rowcou = 0;
    QString namestr = "";
    while (x){
        if (quore->data(quore->index(rowcou, 0)).toString() != namestr){
            namestr = quore->data(quore->index(rowcou, 0)).toString();
            writeStream << quore->data(quore->index(rowcou, 0)).toString()<<"\n";
        }
        writeStream << "\t" << quore->data(quore->index(rowcou, 1)).toString() << "\t" << quore->data(quore->index(rowcou, 2)).toString() << "\t"
                    << quore->data(quore->index(rowcou, 3)).toString() << "\n\n";
        rowcou++;
        --x;
    }


    file.close();
}

