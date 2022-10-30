/********************************************************************************
** Form generated from reading UI file 'ContactInfoskkzNu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTINFOSKKZNU_H
#define CONTACTINFOSKKZNU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *photoLabel;
    QLabel *nameLabel;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *phoneNumberLabel;
    QLabel *label_2;
    QLabel *mailAddressLabel;
    QLabel *label_3;
    QLabel *companyNameLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *creationDateLabel;

    void setupUi(QWidget *ContactInfo)
    {
        if (ContactInfo->objectName().isEmpty())
            ContactInfo->setObjectName(QString::fromUtf8("ContactInfo"));
        ContactInfo->resize(640, 480);
        verticalLayout = new QVBoxLayout(ContactInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        photoLabel = new QLabel(ContactInfo);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(photoLabel);

        nameLabel = new QLabel(ContactInfo);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLabel);

        frame = new QFrame(ContactInfo);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        phoneNumberLabel = new QLabel(frame);
        phoneNumberLabel->setObjectName(QString::fromUtf8("phoneNumberLabel"));

        verticalLayout_2->addWidget(phoneNumberLabel);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        mailAddressLabel = new QLabel(frame);
        mailAddressLabel->setObjectName(QString::fromUtf8("mailAddressLabel"));

        verticalLayout_2->addWidget(mailAddressLabel);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        companyNameLabel = new QLabel(frame);
        companyNameLabel->setObjectName(QString::fromUtf8("companyNameLabel"));

        verticalLayout_2->addWidget(companyNameLabel);


        verticalLayout->addWidget(frame);

        scrollArea = new QScrollArea(ContactInfo);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 620, 218));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        creationDateLabel = new QLabel(ContactInfo);
        creationDateLabel->setObjectName(QString::fromUtf8("creationDateLabel"));
        QFont font;
        font.setPointSize(10);
        creationDateLabel->setFont(font);
        creationDateLabel->setStyleSheet(QString::fromUtf8("color: rgb(192, 191, 188);"));

        verticalLayout->addWidget(creationDateLabel);


        retranslateUi(ContactInfo);

        QMetaObject::connectSlotsByName(ContactInfo);
    } // setupUi

    void retranslateUi(QWidget *ContactInfo)
    {
        ContactInfo->setWindowTitle(QCoreApplication::translate("ContactInfo", "Form", nullptr));
        photoLabel->setText(QCoreApplication::translate("ContactInfo", "DEBUG_PHOTO", nullptr));
        nameLabel->setText(QCoreApplication::translate("ContactInfo", "DEBUG_NAME", nullptr));
        label->setText(QCoreApplication::translate("ContactInfo", "N\302\260T\303\251l\303\251phone", nullptr));
        phoneNumberLabel->setText(QCoreApplication::translate("ContactInfo", "DEBUG_PHONENUMBER", nullptr));
        label_2->setText(QCoreApplication::translate("ContactInfo", "Adresse Mail", nullptr));
        mailAddressLabel->setText(QCoreApplication::translate("ContactInfo", "DEBUG_MAILADDRESS", nullptr));
        label_3->setText(QCoreApplication::translate("ContactInfo", "Entreprise", nullptr));
        companyNameLabel->setText(QCoreApplication::translate("ContactInfo", "DEBUG_COMPANYNAME", nullptr));
        creationDateLabel->setText(QCoreApplication::translate("ContactInfo", "DEBUG_CREATIONDATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactInfo: public Ui_ContactInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTINFOSKKZNU_H
