#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_pushButton_clicked()
{
    QString s=ui->lineEdit->text();
        position=s;
        if(ui->WindowsradioButton->isChecked())
        {
            favouriteOS="Windows";
        }
        if(ui->LinuxradioButton->isChecked())
        {
            favouriteOS="Linux";
        }
        if(ui->MacradioButton->isChecked())
        {
            favouriteOS="Mac";
        }
        accept();
}

void InfoDialog::on_CancelpushButton_clicked()
{
    reject();
}

QString InfoDialog::getPosition() const
{
    return position;
}

QString InfoDialog::getFavouriteOS() const
{
    return favouriteOS;
}
