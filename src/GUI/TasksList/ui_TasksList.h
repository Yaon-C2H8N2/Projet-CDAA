/********************************************************************************
** Form generated from reading UI file 'TasksListTaDGMB.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TASKSLISTTADGMB_H
#define TASKSLISTTADGMB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksList
{
public:
    QHBoxLayout *horizontalLayout;
    QCalendarWidget *calendarWidget;
    QScrollArea *tasksScrollArea;
    QWidget *scrollAreaWidgetContents;

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

        tasksScrollArea = new QScrollArea(TasksList);
        tasksScrollArea->setObjectName(QString::fromUtf8("tasksScrollArea"));
        tasksScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 302, 460));
        tasksScrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(tasksScrollArea);


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

#endif // TASKSLISTTADGMB_H
