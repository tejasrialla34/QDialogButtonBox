#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filter="All Files(*.*);;Text File{(*.txt);;XML File(*.xml)";
        QString fileSama=QFileDialog::getOpenFileName(this,"Open a file","C://",filter);
        QFile file(fileSama);
        if(!file.open(QFile::ReadOnly|QFile::Text))
        {
            QMessageBox::warning(this,"ALLA TEJASRI 212218104015","File not open");
        }
        QTextStream in(&file);
        QString text=in.readAll();
        ui->textEdit->setPlainText(text);
        file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filter="All Files(*.*);;Text File{(*.txt);;XML File(*.xml)";
        QString fileSama=QFileDialog::getOpenFileName(this,"Open a file","C://",filter);
        QFile file(fileSama);
        if(!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::warning(this,"ALLA TEJASRI 212218104015","File not open");
        }
        QTextStream out(&file);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
}
