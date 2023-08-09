#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setHostName("localhost");
    db.setDatabaseName("logistics");
    db.setPassword("228");
    if(db.open()) qDebug()<<"SUCCESS";

    QString text=" Delete from flight; Delete from truck; Delete from truck_summary; Delete from ordering; Delete from orders;  ALTER TABLE truck AUTO_INCREMENT = 1; "
                   " ALTER TABLE truck_summary AUTO_INCREMENT = 1; ALTER TABLE ordering AUTO_INCREMENT = 1; ";
    quore.setQuery(text);

    quore.setQuery("ALTER TABLE orders AUTO_INCREMENT = 1; ALTER TABLE flight AUTO_INCREMENT = 1;");
    pur=new Purchase_window;
    del=new delete_truck;
    dbmodel=new QSqlTableModel(this, db);
    add= new add_order();
    rep=new reports();
    cap=new capital(this);
    number_of_flights=0;
    cap->setModal(true);
    dbmodel->setTable(db.tables().first());
    dbmodel->select();
    dbmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(dbmodel);
    ui->tableselection->addItems(db.tables());
    connect(this, &MainWindow::open_purchase_w,pur,&Purchase_window::open_purchase_w_sl);
    connect(this, &MainWindow::open_purchase_w2,pur,&Purchase_window::open_purchase_w_sl2);
    connect(this, &MainWindow::open_sale,del,&delete_truck::sale_sl);
    connect(this, &MainWindow::order,add,&add_order::order_sl);
    connect(this, &MainWindow::report,rep,&reports::report_sl);
    connect(this, &MainWindow::Capital,cap,&capital::capital_sl);
    connect(cap, &capital::close_capit,this,&MainWindow::close_cap_sl);
    connect(pur, &Purchase_window::change_cap,this,&MainWindow::change_cap_sl);
    connect(del, &delete_truck::change_cap2,this,&MainWindow::change_cap_sl2);
    connect(pur, &Purchase_window::change_cap3,this,&MainWindow::change_cap_sl3);
    connect(pur, &Purchase_window::change_cap2,this,&MainWindow::change_cap_sl2);
    capital_start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableselection_activated(int index)
{
    dbmodel->setTable(db.tables().at(index));
    dbmodel->select();
    ui->tableView->setModel(dbmodel);
}


void MainWindow::on_purchase_buttom_clicked()
{
    emit open_purchase_w2(number_of_flights);
    emit open_purchase_w(capit);
}


void MainWindow::on_sale_buttom_clicked()
{
    emit open_sale();
}


void MainWindow::on_orderButtom_clicked()
{
    emit order();
}


void MainWindow::on_reportbuttom_clicked()
{
    emit report();
}

void MainWindow::capital_start(){
    emit Capital();
}


void MainWindow:: close_cap_sl(int value){
    capit=value;
    ui->capital_lable->setNum(value);
}

void MainWindow::change_cap_sl(int a)
{
    capit-=a;
    ui->capital_lable->setNum(capit);
}


void MainWindow::change_cap_sl2(int a)
{
    capit=capit+a;
    ui->capital_lable->setNum(capit);
}

void MainWindow::change_cap_sl3(int a)
{
    number_of_flights=a;
}


