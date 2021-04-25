#include "widget.h"
#include "ui_widget.h"
#include<infodialog.h>
#include<QDebug>
#include<QDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ProvideInfopushButton_clicked()
{
     InfoDialog *dialog=new InfoDialog(this);
     /*
     int ret=dialog->exec();
     if(ret==QDialog::Accepted)
     {
             QString position=dialog->getPosition();
             QString OS=dialog->getFavouriteOS();
             qDebug()<<"Dialog Accepted ,Position is "<<position<<" and Favourite OS is "<<OS;
             ui->label->setText("Your Position is: "+position+" and Your Favourite OS is "+OS);

     }
     */
     connect(dialog,&InfoDialog::accepted,[=](){
             QString position=dialog->getPosition();
             QString os=dialog->getFavouriteOS();
             qDebug()<<"Dialog Accepted ,Position is "<<position<<" and Favourite OS is "<<os;
             ui->label->setText("Your position is: "+position+" and your Favourite OS is "+os);
         });
                 connect(dialog,&InfoDialog::rejected,[=](){
                     QString position=dialog->getPosition();
                     QString os=dialog->getFavouriteOS();
                     qDebug()<<"Dialog Rejected";

                 });
                 dialog->show();
                 dialog->raise();
                 dialog->activateWindow();
}
