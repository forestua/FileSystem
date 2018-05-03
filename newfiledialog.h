#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class NewFileDialog;
}

// file data
struct FileData
{
    QString name;
    QString ext;
    unsigned size;
};

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(QWidget *parent = 0);
    ~NewFileDialog();
    void GetValues(QString& name);

    QString GetName();
    QString GetExt();

signals:
    void sendData(struct FileData);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewFileDialog *ui;
};

#endif // NEWFILEDIALOG_H
