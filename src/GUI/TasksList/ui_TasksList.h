/********************************************************************************
** Form generated from reading UI file 'TasksListeEWXNi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TASKSLISTEEWXNI_H
#define TASKSLISTEEWXNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksList
{
public:
    QHBoxLayout *horizontalLayout;
    QCalendarWidget *calendarWidget;
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
        horizontalLayout = new QHBoxLayout(TasksList);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        calendarWidget = new QCalendarWidget(TasksList);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        horizontalLayout->addWidget(calendarWidget);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 302, 460));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tasksScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(tasksScrollArea);


        horizontalLayout->addWidget(frame);


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

#endif // TASKSLISTEEWXNI_H
