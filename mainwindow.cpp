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

    newFileDlg = new NewFileDialog();
    newDirectoryDlg = new NewDirectoryDialog();

    ui->treeWidget->setColumnCount(4);
    QStringList list;
    list << "Name" << "Extension" << "Last access date" << "Size";
    ui->treeWidget->setHeaderLabels(list);

    connect(ui->createFile, SIGNAL(triggered()), newFileDlg, SLOT(show()));
    connect(ui->createFolder, SIGNAL(triggered()), newDirectoryDlg, SLOT(show()));
    connect(newFileDlg, SIGNAL(sendData(FileData)), this, SLOT(receiveFileData(FileData)));
    connect(newDirectoryDlg, SIGNAL(sendData(FolderData)), this, SLOT(receiveFolderData(FolderData)));

    ShowFiles();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowFiles()
{
    ui->treeWidget->clear();

    QList<QTreeWidgetItem *> items;
    /*auto files = fileSystem->GetFiles();
    for (int i = 0; i < files.size(); ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(files[i])));
    ui->treeWidget->insertTopLevelItems(0, items);*/

    //1) Show root folder
    File* folder;
    for (int i = 0; i < fileSystem->fileArray.size(); i++)
    {
        if (fileSystem->fileArray[i]->name == "/")
        {
            folder = fileSystem->fileArray[i];
        }
    }

    expandTreeSelectedFolder(folder);
}

    //Formatting file system
void MainWindow::format()
{
    //QFile disk(DISK_NAME);

}

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

void MainWindow::receiveFileData(FileData fileData)
{
//    QMessageBox msgBox;
//    msgBox.setText(fileData.name + "." + fileData.ext);
//    msgBox.setStandardButtons(QMessageBox::Ok);
//    msgBox.exec();

    fileSystem->NewFile(fileData.name, fileData.ext);

    ShowFiles();
}

void MainWindow::receiveFolderData(FolderData folderData)
{
//    QMessageBox msgBox;
//    msgBox.setText(folderData.name);
//    msgBox.setStandardButtons(QMessageBox::Ok);
//    msgBox.exec();

    fileSystem->NewFile(folderData.name, "");

    ShowFiles();
}

void MainWindow::on_exit_triggered()
{
    //TODO: close file
    this->close();
}

void MainWindow::on_format_triggered()
{
    fileSystem->Format();
    ShowFiles();
}

int MainWindow::expandTreeSelectedFolder(File* f)
{
    return 0;
}
