/********************************************************************************
** Form generated from reading UI file 'InteractionCreatorNZHjWS.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INTERACTIONCREATORNZHJWS_H
#define INTERACTIONCREATORNZHJWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InteractionCreator
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InteractionCreator)
    {
        if (InteractionCreator->objectName().isEmpty())
            InteractionCreator->setObjectName(QString::fromUtf8("InteractionCreator"));
        InteractionCreator->resize(640, 480);
        verticalLayout = new QVBoxLayout(InteractionCreator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(InteractionCreator);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        textEdit = new QTextEdit(InteractionCreator);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(InteractionCreator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InteractionCreator);
        QObject::connect(buttonBox, SIGNAL(accepted()), InteractionCreator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InteractionCreator, SLOT(reject()));

        QMetaObject::connectSlotsByName(InteractionCreator);
    } // setupUi

    void retranslateUi(QDialog *InteractionCreator)
    {
        InteractionCreator->setWindowTitle(QCoreApplication::translate("InteractionCreator", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("InteractionCreator", "DEBUG_TITLE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InteractionCreator: public Ui_InteractionCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INTERACTIONCREATORNZHJWS_H
