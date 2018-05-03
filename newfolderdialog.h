#ifndef NEWDIRECTORYDIALOG_H
#define NEWDIRECTORYDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class NewDirectoryDialog;
}

// folder data
struct FolderData
{
    QString name;
};

class NewDirectoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDirectoryDialog(QWidget *parent = 0);
    ~NewDirectoryDialog();

private:
    Ui::NewDirectoryDialog *ui;
};

#endif // NEWDIRECTORYDIALOG_H
