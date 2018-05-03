#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DISK_SIZE 200
#define DISK_NAME "filesystem.disk"

#include <QMainWindow>
#include <QStringList>
#include "filesystem.h"
#include "newfolderdialog.h"
#include "newfiledialog.h"
#include "treewidget.h"

namespace Ui {
    class MainWindow;
}

// file, folder data

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    NewFileDialog *newFileDlg;
    NewDirectoryDialog *newDirectoryDlg;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void recieveNewFileData(FileData fileData);
    void recieveNewDirectoryData(FolderData folderData);

private slots:
    void on_action_triggered();

    void on_action_5_triggered();

    //void format();

    void on_createFile_triggered();

    void on_exit_triggered();

private:
    Ui::MainWindow *ui;
    FileSystem* fileSystem;
    TreeWidget* treeWidget;
};

#endif // MAINWINDOW_H
