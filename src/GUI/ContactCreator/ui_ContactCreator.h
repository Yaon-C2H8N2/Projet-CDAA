/********************************************************************************
** Form generated from reading UI file 'ContactCreatorEKCVOq.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTCREATOREKCVOQ_H
#define CONTACTCREATOREKCVOQ_H

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
    QPushButton *pushButton;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ContactCreator)
    {
        if (ContactCreator->objectName().isEmpty())
            ContactCreator->setObjectName(QString::fromUtf8("ContactCreator"));
        ContactCreator->resize(640, 480);
        ContactCreator->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(ContactCreator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(ContactCreator);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton);

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
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addWidget(frame);

        lineEdit_3 = new QLineEdit(ContactCreator);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(ContactCreator);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(ContactCreator);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        frame_2 = new QFrame(ContactCreator);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addWidget(frame_2);


        retranslateUi(ContactCreator);

        QMetaObject::connectSlotsByName(ContactCreator);
    } // setupUi

    void retranslateUi(QWidget *ContactCreator)
    {
        ContactCreator->setWindowTitle(QCoreApplication::translate("ContactCreator", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ContactCreator", "PushButton", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Pr\303\251nom", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Nom", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("ContactCreator", "N\302\260T\303\251l\303\251phone", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Adresse mail", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("ContactCreator", "Entreprise", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ContactCreator", "Annuler", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ContactCreator", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactCreator: public Ui_ContactCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTCREATOREKCVOQ_H
