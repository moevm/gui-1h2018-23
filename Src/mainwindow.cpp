#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    _gamescore = std::shared_ptr<gameScore>  (new gameScore);
    connect(_gamescore.get(),&gameScore::firstWindow,this,&MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    _widget = std::shared_ptr<Widget> (new Widget);
    connect(_widget.get(),&Widget::firstWindow,this,&MainWindow::show);
    _widget->show();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    
    _gamescore->show();
    this->close();
}
