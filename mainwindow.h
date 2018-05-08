#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DISK_SIZE 200

#include <QMainWindow>
#include <QStringList>
#include "filesystem.h"
#include "newfolderdialog.h"
#include "newfiledialog.h"

namespace Ui {
    class MainWindow;
    // file, folder data
    struct FileData
    {
        QString name;
        QString ext;
        unsigned size;
    };
    struct FolderData
    {
        QString name;
    };
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    NewFileDialog *newFileDlg;
    NewDirectoryDialog *newDirectoryDlg;

    void ShowFiles();
    int expandTreeSelectedFolder(File* f);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void receiveFileData(FileData fileData);
    void receiveFolderData(FolderData folderData);

private slots:
    void on_action_triggered();
    void on_action_5_triggered();
    void format();
    void on_createFile_triggered();
    void on_exit_triggered();
    void on_format_triggered();

private:
    Ui::MainWindow *ui;
    FileSystem* fileSystem;
};

#endif // MAINWINDOW_H
