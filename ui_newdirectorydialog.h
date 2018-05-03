/********************************************************************************
** Form generated from reading UI file 'newdirectorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIRECTORYDIALOG_H
#define UI_NEWDIRECTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NewDirectoryDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *NewDirectoryDialog)
    {
        if (NewDirectoryDialog->objectName().isEmpty())
            NewDirectoryDialog->setObjectName(QStringLiteral("NewDirectoryDialog"));
        NewDirectoryDialog->resize(400, 159);
        buttonBox = new QDialogButtonBox(NewDirectoryDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(NewDirectoryDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 40, 141, 20));
        label_2 = new QLabel(NewDirectoryDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 47, 13));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label = new QLabel(NewDirectoryDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 111, 13));
        label->setMaximumSize(QSize(16777215, 13));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        retranslateUi(NewDirectoryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewDirectoryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewDirectoryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewDirectoryDialog);
    } // setupUi

    void retranslateUi(QDialog *NewDirectoryDialog)
    {
        NewDirectoryDialog->setWindowTitle(QApplication::translate("NewDirectoryDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("NewDirectoryDialog", "Name:", nullptr));
        label->setText(QApplication::translate("NewDirectoryDialog", "New directory:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewDirectoryDialog: public Ui_NewDirectoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIRECTORYDIALOG_H
