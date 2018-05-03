/********************************************************************************
** Form generated from reading UI file 'newfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILEDIALOG_H
#define UI_NEWFILEDIALOG_H

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

class Ui_NewFileDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *editName;
    QLineEdit *editExt;
    QLineEdit *editSize;

    void setupUi(QDialog *NewFileDialog)
    {
        if (NewFileDialog->objectName().isEmpty())
            NewFileDialog->setObjectName(QStringLiteral("NewFileDialog"));
        NewFileDialog->resize(395, 230);
        buttonBox = new QDialogButtonBox(NewFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NewFileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 71, 13));
        label->setMaximumSize(QSize(16777215, 13));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(NewFileDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 40, 47, 13));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(NewFileDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 70, 61, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(NewFileDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 100, 61, 16));
        label_4->setFont(font1);
        editName = new QLineEdit(NewFileDialog);
        editName->setObjectName(QStringLiteral("editName"));
        editName->setGeometry(QRect(110, 40, 141, 20));
        editExt = new QLineEdit(NewFileDialog);
        editExt->setObjectName(QStringLiteral("editExt"));
        editExt->setGeometry(QRect(110, 70, 141, 20));
        editSize = new QLineEdit(NewFileDialog);
        editSize->setObjectName(QStringLiteral("editSize"));
        editSize->setGeometry(QRect(110, 100, 141, 20));

        retranslateUi(NewFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewFileDialog);
    } // setupUi

    void retranslateUi(QDialog *NewFileDialog)
    {
        NewFileDialog->setWindowTitle(QApplication::translate("NewFileDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("NewFileDialog", "New File", nullptr));
        label_2->setText(QApplication::translate("NewFileDialog", "Name:", nullptr));
        label_3->setText(QApplication::translate("NewFileDialog", "Extension:", nullptr));
        label_4->setText(QApplication::translate("NewFileDialog", "Size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewFileDialog: public Ui_NewFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILEDIALOG_H
