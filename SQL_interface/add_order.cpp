#include "add_order.h"
#include "ui_add_order.h"

add_order::add_order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_order)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    query =new QSqlQueryModel;
}

add_order::~add_order()
{
    delete ui;
}

void add_order::order_sl()
{
    this->show();
}

void add_order::on_close_clicked()
{
    this->close();
}


void add_order::on_add_clicked() {
    QString Text = " set @ct_id = (select cargo_type_id from cargo_type where cargo_type = '"+ ui->cargo_type->text() + "');" +
                   " set @st_id = (select city_id from city where name_city = '" + ui->start->text() + "');" +
                   " set @f_id = (select city_id from city where name_city = '" + ui->finish->text() + "');" +
                   " insert into ordering(volume, cargo_type_id, start_city_id, finish_city_id, data_ordering)"
                   " values(" + ui->volume->text() + ", @ct_id, @st_id, @f_id, '" + ui->date_line->text() + "');"
                   " insert into orders(cargo_type, start_city, finich_city, date_ordering, volume) "
                   " values('" + ui->cargo_type->text()+ "','" +ui->start->text() + "','"
                   + ui->finish->text() +"','"+ui->date_line->text()+"',"
                   +ui->volume->text()+ ");";

    query->setQuery(Text);

    query->setQuery("select * from ordering;");
    int x = query->rowCount();
    query->setQuery("set @ord_id = (select max(order_id) from orders);");


    while(x != 0){
    Text = "set @t_id = (select truck_id from truck WHERE cargo_type_id = @ct_id ORDER BY free_date asc, load_capacity desc LIMIT 1);";

    query->setQuery(Text);


    Text="	select datediff(' "+ ui->date_line->text() + " ',free_date)"
                                                              " from truck where truck_id = @t_id;";
    query->setQuery(Text);

    int x1 = query->data(query->index(0,0)).toInt();

    if(x1>0){
           Text = " update truck set  free_date = '" + ui->date_line->text() +
                  "' where truck_id = @t_id;";
    }

    query->setQuery(Text);

    Text = "set @d_before_s = (SELECT distance from distance d inner join truck t on t.city_id = d.city1_id "
           "where truck_id = @t_id and city2_id = @st_id);";

    query->setQuery(Text);

    query->setQuery("select @d_before_s;");
    int bef = query->data(query->index(0,0)).toInt();


    Text = "set @d_after_s = (select distance from distance where city1_id = @st_id and city2_id = @f_id);";

    query->setQuery(Text);

    if(bef!=0){
    Text="insert into flight(order_id, date_start, date_finish, "
         "  cargo_type, truck_id, city1_id, city2_id)"
         " values((select max(order_id) from orders),"
         " (select free_date from truck where truck_id=@t_id),"
         " adddate((select free_date from truck where truck_id=@t_id), @d_before_s),"
         " false, @t_id, (select city_id from truck where truck_id=@t_id), @st_id);";
    }

    query->setQuery(Text);

    Text="insert into flight(order_id, date_start, date_finish, "
           " cargo_type, truck_id, city1_id, city2_id)"
           " values((select max(order_id) from orders),"
           " adddate((select free_date from truck where truck_id=@t_id), @d_before_s),"
           " adddate((select free_date from truck where truck_id=@t_id), @d_before_s+@d_after_s),"
           " true, @t_id, @st_id, @f_id);";

    query->setQuery(Text);

    Text = "update truck set free_date = adddate(free_date, @d_before_s + @d_after_s) where truck_id=@t_id;"
           " update truck set city_id=@f_id where truck_id=@t_id;";

    query->setQuery(Text);

    Text = "update ordering, truck set volume = volume - load_capacity where truck_id = @t_id;";
    query->setQuery(Text);
    Text = "delete from ordering where volume <= 0;";
    query->setQuery(Text);
    query->setQuery("select * from ordering;");
    x = query->rowCount();
    }

    Text="DELETE FROM flight  WHERE city1_id=city2_id;";
    query->setQuery(Text);

    ui->cargo_type->clear();
    ui->finish->clear();
    ui->start->clear();
    ui->volume->clear();
    ui->date_line->clear();
}

