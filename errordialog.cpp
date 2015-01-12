#include "errordialog.h"
#include "ui_errordialog.h"
#include <QString>

ErrorDialog::ErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::setErrorMessage(QString message){
    ui->errMessage->setText( message );
}
