#include "newfiledialog.h"
#include "ui_newfiledialog.h"
#include <QMessageBox>

NewFileDialog::NewFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);

    //connect(sendData, SIGNAL(QDialogButtonBox::accepted()), parent, SLOT(onButtonSend()));
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}

void NewFileDialog::on_buttonBox_accepted()
{
    FileData fileData;
    fileData.name = ui->editName->text();
    fileData.ext = ui->editExt->text();
    fileData.size = ui->editSize->text().toUInt();
    emit sendData(fileData);
}

void NewFileDialog::on_buttonBox_rejected()
{

}

QString NewFileDialog::GetName()
{
    return ui->editName->text();
}

QString NewFileDialog::GetExt()
{
    return ui->editExt->text();
}

void NewFileDialog::GetValues(QString& name)
{
    name = ui->editName->text();
}

void NewFileDialog::on_buttonBox_clicked(QAbstractButton *button)
{

}
