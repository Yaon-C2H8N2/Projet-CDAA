/********************************************************************************
** Form generated from reading UI file 'ContactListgDVHzf.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTLISTGDVHZF_H
#define CONTACTLISTGDVHZF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactList
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *dataInfoLabel;

    void setupUi(QWidget *ContactList)
    {
        if (ContactList->objectName().isEmpty())
            ContactList->setObjectName(QString::fromUtf8("ContactList"));
        ContactList->resize(640, 480);
        verticalLayout = new QVBoxLayout(ContactList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ContactList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        dateEdit_2 = new QDateEdit(frame);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout->addWidget(dateEdit_2);

        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(frame);

        scrollArea = new QScrollArea(ContactList);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 622, 403));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        dataInfoLabel = new QLabel(ContactList);
        dataInfoLabel->setObjectName(QString::fromUtf8("dataInfoLabel"));
        dataInfoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(dataInfoLabel);


        retranslateUi(ContactList);

        QMetaObject::connectSlotsByName(ContactList);
    } // setupUi

    void retranslateUi(QWidget *ContactList)
    {
        ContactList->setWindowTitle(QCoreApplication::translate("ContactList", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ContactList", "Recherche par nom", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ContactList", "Recherche par entreprise", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ContactList", "Recherche par date cr\303\251ation", nullptr));

        pushButton->setText(QCoreApplication::translate("ContactList", "+", nullptr));
        dataInfoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactList: public Ui_ContactList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTLISTGDVHZF_H
