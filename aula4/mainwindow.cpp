#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<fstream>
#include<string>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setFocus();
    ofstream gravar;
    string a,b,c;
    gravar.open("teste_arq11.txt", fstream::app);
    a = string(ui->lineEdit->text().toStdString());
    b = string(ui->lineEdit_2->text().toStdString());
    c = string(ui->lineEdit_3->text().toStdString());
    gravar << a << "\n" << b << "\n" << c << "\n";
    gravar.close();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    string al;
    ifstream ler;
    ler.open("teste_arq11.txt");
    while(ler) {
        getline(ler,al);
        if(al!=""){
            const QString s = QString::fromStdString(al);
            ui->listWidget->addItem(s);
        }

    }
}
