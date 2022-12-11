/********************************************************************************
** Form generated from reading UI file 'TasksListCWosvd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TASKSLISTCWOSVD_H
#define TASKSLISTCWOSVD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksList
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *fromDateEdit;
    QLabel *label_2;
    QDateEdit *toDateEdit;
    QPushButton *validateButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *reinitButton;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QScrollArea *tasksScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *TasksList)
    {
        if (TasksList->objectName().isEmpty())
            TasksList->setObjectName(QString::fromUtf8("TasksList"));
        TasksList->resize(640, 480);
        verticalLayout_3 = new QVBoxLayout(TasksList);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_2 = new QFrame(TasksList);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fromDateEdit = new QDateEdit(frame_2);
        fromDateEdit->setObjectName(QString::fromUtf8("fromDateEdit"));

        horizontalLayout->addWidget(fromDateEdit);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        toDateEdit = new QDateEdit(frame_2);
        toDateEdit->setObjectName(QString::fromUtf8("toDateEdit"));

        horizontalLayout->addWidget(toDateEdit);

        validateButton = new QPushButton(frame_2);
        validateButton->setObjectName(QString::fromUtf8("validateButton"));

        horizontalLayout->addWidget(validateButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reinitButton = new QPushButton(frame_2);
        reinitButton->setObjectName(QString::fromUtf8("reinitButton"));

        horizontalLayout->addWidget(reinitButton);


        verticalLayout_3->addWidget(frame_2);

        frame = new QFrame(TasksList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tasksScrollArea = new QScrollArea(frame);
        tasksScrollArea->setObjectName(QString::fromUtf8("tasksScrollArea"));
        tasksScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 620, 406));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tasksScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(tasksScrollArea);


        verticalLayout_3->addWidget(frame);


        retranslateUi(TasksList);

        QMetaObject::connectSlotsByName(TasksList);
    } // setupUi

    void retranslateUi(QWidget *TasksList)
    {
        TasksList->setWindowTitle(QCoreApplication::translate("TasksList", "Form", nullptr));
        label->setText(QCoreApplication::translate("TasksList", "Du", nullptr));
        label_2->setText(QCoreApplication::translate("TasksList", "Au", nullptr));
        validateButton->setText(QCoreApplication::translate("TasksList", "Valider", nullptr));
        reinitButton->setText(QCoreApplication::translate("TasksList", "Liste Compl\303\250te", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TasksList: public Ui_TasksList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TASKSLISTCWOSVD_H
