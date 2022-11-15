/********************************************************************************
** Form generated from reading UI file 'ContactModifierfvKaFV.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTMODIFIERFVKAFV_H
#define CONTACTMODIFIERFVKAFV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *photoPathEdit;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *phoneNumberEdit;
    QLineEdit *mailEdit;
    QLineEdit *companyNameEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(640, 480);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        photoPathEdit = new QPushButton(Dialog);
        photoPathEdit->setObjectName(QString::fromUtf8("photoPathEdit"));

        verticalLayout->addWidget(photoPathEdit);

        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        firstNameEdit = new QLineEdit(frame);
        firstNameEdit->setObjectName(QString::fromUtf8("firstNameEdit"));

        horizontalLayout->addWidget(firstNameEdit);

        lastNameEdit = new QLineEdit(frame);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));

        horizontalLayout->addWidget(lastNameEdit);


        verticalLayout->addWidget(frame);

        phoneNumberEdit = new QLineEdit(Dialog);
        phoneNumberEdit->setObjectName(QString::fromUtf8("phoneNumberEdit"));

        verticalLayout->addWidget(phoneNumberEdit);

        mailEdit = new QLineEdit(Dialog);
        mailEdit->setObjectName(QString::fromUtf8("mailEdit"));

        verticalLayout->addWidget(mailEdit);

        companyNameEdit = new QLineEdit(Dialog);
        companyNameEdit->setObjectName(QString::fromUtf8("companyNameEdit"));

        verticalLayout->addWidget(companyNameEdit);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        photoPathEdit->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        firstNameEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "Pr\303\251nom", nullptr));
        lastNameEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "Nom", nullptr));
        phoneNumberEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "N\302\260T\303\251l\303\251phone", nullptr));
        mailEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "Adresse mail", nullptr));
        companyNameEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "Entreprise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTMODIFIERFVKAFV_H
