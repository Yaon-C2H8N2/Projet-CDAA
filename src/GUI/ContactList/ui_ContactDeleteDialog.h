/********************************************************************************
** Form generated from reading UI file 'ContactDeleteDialogHItegP.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTDELETEDIALOGHITEGP_H
#define CONTACTDELETEDIALOGHITEGP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContactDeleteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ContactDeleteDialog)
    {
        if (ContactDeleteDialog->objectName().isEmpty())
            ContactDeleteDialog->setObjectName(QString::fromUtf8("ContactDeleteDialog"));
        ContactDeleteDialog->resize(317, 70);
        verticalLayout = new QVBoxLayout(ContactDeleteDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ContactDeleteDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(ContactDeleteDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ContactDeleteDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ContactDeleteDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ContactDeleteDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ContactDeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *ContactDeleteDialog)
    {
        ContactDeleteDialog->setWindowTitle(QCoreApplication::translate("ContactDeleteDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ContactDeleteDialog", "Voulez-vous vraiment supprimer ce contact ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactDeleteDialog: public Ui_ContactDeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTDELETEDIALOGHITEGP_H
