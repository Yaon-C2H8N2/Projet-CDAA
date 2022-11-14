/********************************************************************************
** Form generated from reading UI file 'InteractionViewerQbedFA.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INTERACTIONVIEWERQBEDFA_H
#define INTERACTIONVIEWERQBEDFA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InteractionViewer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *dateLabel;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QPushButton *deleteButton;

    void setupUi(QWidget *InteractionViewer)
    {
        if (InteractionViewer->objectName().isEmpty())
            InteractionViewer->setObjectName(QString::fromUtf8("InteractionViewer"));
        InteractionViewer->resize(640, 159);
        verticalLayout = new QVBoxLayout(InteractionViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dateLabel = new QLabel(InteractionViewer);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        verticalLayout->addWidget(dateLabel);

        frame = new QFrame(InteractionViewer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout->addWidget(frame);


        retranslateUi(InteractionViewer);

        QMetaObject::connectSlotsByName(InteractionViewer);
    } // setupUi

    void retranslateUi(QWidget *InteractionViewer)
    {
        InteractionViewer->setWindowTitle(QCoreApplication::translate("InteractionViewer", "Form", nullptr));
        dateLabel->setText(QCoreApplication::translate("InteractionViewer", "TextLabel", nullptr));
        deleteButton->setText(QCoreApplication::translate("InteractionViewer", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InteractionViewer: public Ui_InteractionViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INTERACTIONVIEWERQBEDFA_H
