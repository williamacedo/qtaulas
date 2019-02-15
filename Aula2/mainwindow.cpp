#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<carro.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

carro temp[3];
int a=0;

void MainWindow::on_pushButton_clicked()
{
    temp[a].set_fab(ui->lineEdit->text());
    temp[a].set_ano(ui->lineEdit_2->text());
    temp[a].set_valor(ui->lineEdit_3->text());
    ui->label_5->setText(QString("%1").arg(a+1)+ QString(" de 3"));
    a++;
    ui->lcdNumber->display(a);
    if(a==3){
        ui->pushButton->setEnabled(0);
        ui->lineEdit->setEnabled(0);
        ui->lineEdit_2->setEnabled(0);
        ui->lineEdit_3->setEnabled(0);
        ui->pushButton_2->setEnabled(1);
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_2_clicked()
{
    a=0;
    while(a<3){
        ui->listWidget->addItem(temp[a].ret_fab());
        ui->listWidget->addItem(temp[a].ret_ano());
        ui->listWidget->addItem(temp[a].ret_valor());
        a++;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    for(int a=0;a<3;a++){
        if(ui->lineEdit_4->text()==temp[a].ret_fab()){
            ui->lineEdit->clear();
            ui->listWidget->addItem(temp[a].ret_fab());
            ui->listWidget->addItem(temp[a].ret_ano());
            ui->listWidget->addItem(temp[a].ret_valor());
        }
    }
}
