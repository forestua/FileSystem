#include "newfolderdialog.h"
#include "ui_newdirectorydialog.h"

NewDirectoryDialog::NewDirectoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDirectoryDialog)
{
    ui->setupUi(this);
}

NewDirectoryDialog::~NewDirectoryDialog()
{
    delete ui;
}
