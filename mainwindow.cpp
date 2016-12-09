#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE");
    myDatabase.setDatabaseName("C:/sqlite/MyDatabase.db");

    if(!myDatabase.open())
    {
        ui->labelDbStatusValue->setText("Failed to open the database.");
    }
    else
    {
        ui->labelDbStatusValue->setText("Connected");
    }

    QSqlQuery query;
    query.exec("create table person "
              "(id integer primary key, "
              "firstname varchar(20), "
              "lastname varchar(30), "
              "age integer)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
