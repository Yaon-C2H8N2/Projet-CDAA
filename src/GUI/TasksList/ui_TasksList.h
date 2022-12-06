/********************************************************************************
** Form generated from reading UI file 'TasksListDzzUod.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TASKSLISTDZZUOD_H
#define TASKSLISTDZZUOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksList
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
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
        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        dateEdit_2 = new QDateEdit(frame_2);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout->addWidget(dateEdit_2);


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
    } // retranslateUi

};

namespace Ui {
    class TasksList: public Ui_TasksList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TASKSLISTDZZUOD_H
