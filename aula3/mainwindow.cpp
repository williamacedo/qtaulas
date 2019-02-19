#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<vector>
#include "aluno.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->tabWidget->setCurrentIndex(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Nome" << "Endereço" << "Idade");
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Nome" << "Endereço" << "Idade");
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<Aluno> Escola;
vector<Aluno> Consulta;

void MainWindow::on_pushButton_clicked()
{
    Aluno temp;
    temp.set_nome(ui->lineEdit->text());
    temp.set_endereco(ui->lineEdit_2->text());
    temp.set_idade(ui->lineEdit_3->text());
    Escola.push_back(temp);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit->setFocus();
    ui->label_5->setText(QString("%1").arg(Escola.size()));
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableWidget->setRowCount(Escola.size());
    for(int x=0;x<Escola.size();x++){
        ui->tableWidget->setItem(x,0,new QTableWidgetItem(Escola.at(x).ret_nome()));
        ui->tableWidget->setItem(x,1,new QTableWidgetItem(Escola.at(x).ret_endereco()));
        ui->tableWidget->setItem(x,2,new QTableWidgetItem(Escola.at(x).ret_idade()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int conte=0;
    Aluno temp2;
    for(int x1=0;x1<Escola.size();x1++){
        if(ui->lineEdit_4->text()==Escola.at(x1).ret_nome()){
            Consulta.push_back(Escola.at(x1));
            conte++;
        }
    }
    ui->tableWidget_2->setRowCount(conte);
    for(int x=0;x<Consulta.size();x++) {
        ui->tableWidget_2->setItem(x,0,new QTableWidgetItem(Consulta.at(x).ret_nome()));
        ui->tableWidget_2->setItem(x,1,new QTableWidgetItem(Consulta.at(x).ret_endereco()));
        ui->tableWidget_2->setItem(x,2,new QTableWidgetItem(Consulta.at(x).ret_idade()));
    }
    Consulta.clear();
}
