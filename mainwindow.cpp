#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include "newfiledialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileSystem = new FileSystem();
    treeWidget = new TreeWidget();

    newFileDlg = new NewFileDialog();
    newDirectoryDlg = new NewDirectoryDialog();
    connect(ui->createFile, SIGNAL(triggered()), newFileDlg, SLOT(show()));
    connect(newFileDlg, SIGNAL(sendData(struct FileData)), this, SLOT(recieveNewFileData(struct FileData)));
    connect(ui->createFolder, SIGNAL(triggered()), newDirectoryDlg, SLOT(show()));

    //tree
    ui->treeWidget->setColumnCount(4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::recieveNewFileData(FileData fileData)
{
    QMessageBox msgBox;
        msgBox.setText(fileData.name);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        msgBox.setText(fileData.ext);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
//        msgBox.setText(fileData.size);
//        msgBox.setStandardButtons(QMessageBox::Ok);
 //       msgBox.exec();
}

//Formatting file system
/*void MainWindow::format()
{
    //QFile disk(DISK_NAME);

}*/

void MainWindow::on_action_triggered()
{

}

void MainWindow::on_action_5_triggered()
{

}

void MainWindow::on_createFile_triggered()
{
//    NewFileDialog newFileDlg;
//    newFileDlg.setModal(true);
//    if (newFileDlg.exec())
//    {
//        QString name = newFileDlg.GetName();
//        QString ext = newFileDlg.GetExt();

//        QMessageBox msgBox;
//        msgBox.setText(name);
//        msgBox.setStandardButtons(QMessageBox::Ok);
//        msgBox.exec();

//        fileSystem->NewFile(name, ext);

//        auto files = fileSystem->ShowFiles();
//    }
}



void MainWindow::recieveNewDirectoryData(FolderData folderData)
{
    QMessageBox msgBox;
    msgBox.setText(folderData.name);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::on_exit_triggered()
{
    //TODO: close file
    this->close();
}
