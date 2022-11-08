/********************************************************************************
** Form generated from reading UI file 'ContactCreatorrryixF.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTCREATORRRYIXF_H
#define CONTACTCREATORRRYIXF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactCreator
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *contactPicturePushButton;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *mailAddressLineEdit;
    QLineEdit *companyNameLineEdit;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelPushButton;
    QPushButton *validatePushButton;

    void setupUi(QWidget *ContactCreator)
    {
        if (ContactCreator->objectName().isEmpty())
            ContactCreator->setObjectName(QString::fromUtf8("ContactCreator"));
        ContactCreator->resize(640, 480);
        ContactCreator->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(ContactCreator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contactPicturePushButton = new QPushButton(ContactCreator);
        contactPicturePushButton->setObjectName(QString::fromUtf8("contactPicturePushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contactPicturePushButton->sizePolicy().hasHeightForWidth());
        contactPicturePushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(contactPicturePushButton);

        frame = new QFrame(ContactCreator);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        firstNameLineEdit = new QLineEdit(frame);
        firstNameLineEdit->setObjectName(QString::fromUtf8("firstNameLineEdit"));

        horizontalLayout->addWidget(firstNameLineEdit);

        lastNameLineEdit = new QLineEdit(frame);
        lastNameLineEdit->setObjectName(QString::fromUtf8("lastNameLineEdit"));

        horizontalLayout->addWidget(lastNameLineEdit);


        verticalLayout->addWidget(frame);

        phoneNumberLineEdit = new QLineEdit(ContactCreator);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));

        verticalLayout->addWidget(phoneNumberLineEdit);

        mailAddressLineEdit = new QLineEdit(ContactCreator);
        mailAddressLineEdit->setObjectName(QString::fromUtf8("mailAddressLineEdit"));

        verticalLayout->addWidget(mailAddressLineEdit);

        companyNameLineEdit = new QLineEdit(ContactCreator);
        companyNameLineEdit->setObjectName(QString::fromUtf8("companyNameLineEdit"));

        verticalLayout->addWidget(companyNameLineEdit);

        frame_2 = new QFrame(ContactCreator);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cancelPushButton = new QPushButton(frame_2);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_2->addWidget(cancelPushButton);

        validatePushButton = new QPushButton(frame_2);
        validatePushButton->setObjectName(QString::fromUtf8("validatePushButton"));
        validatePushButton->setEnabled(false);

        horizontalLayout_2->addWidget(validatePushButton);


        verticalLayout->addWidget(frame_2);


        retranslateUi(ContactCreator);

        QMetaObject::connectSlotsByName(ContactCreator);
    } // setupUi

    void retranslateUi(QWidget *ContactCreator)
    {
        ContactCreator->setWindowTitle(QCoreApplication::translate("ContactCreator", "Form", nullptr));
        contactPicturePushButton->setText(QCoreApplication::translate("ContactCreator", "PushButton", nullptr));
        firstNameLineEdit->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Pr\303\251nom", nullptr));
        lastNameLineEdit->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Nom", nullptr));
        phoneNumberLineEdit->setPlaceholderText(QCoreApplication::translate("ContactCreator", "N\302\260T\303\251l\303\251phone", nullptr));
        mailAddressLineEdit->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Adresse mail", nullptr));
        companyNameLineEdit->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Entreprise", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("ContactCreator", "Annuler", nullptr));
        validatePushButton->setText(QCoreApplication::translate("ContactCreator", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactCreator: public Ui_ContactCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTCREATORRRYIXF_H
