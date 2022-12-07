/********************************************************************************
** Form generated from reading UI file 'MainWindowVYbLbS.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWVYBLBS_H
#define MAINWINDOWVYBLBS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *contactTab;
    QHBoxLayout *horizontalLayout;
    QWidget *contactListWidget;
    QWidget *contactInfoWidget;
    QWidget *newContactWidget;
    QWidget *taskTab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(853, 640);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        contactTab = new QWidget();
        contactTab->setObjectName(QString::fromUtf8("contactTab"));
        horizontalLayout = new QHBoxLayout(contactTab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        contactListWidget = new QWidget(contactTab);
        contactListWidget->setObjectName(QString::fromUtf8("contactListWidget"));

        horizontalLayout->addWidget(contactListWidget);

        contactInfoWidget = new QWidget(contactTab);
        contactInfoWidget->setObjectName(QString::fromUtf8("contactInfoWidget"));

        horizontalLayout->addWidget(contactInfoWidget);

        newContactWidget = new QWidget(contactTab);
        newContactWidget->setObjectName(QString::fromUtf8("newContactWidget"));

        horizontalLayout->addWidget(newContactWidget);

        tabWidget->addTab(contactTab, QString());
        taskTab = new QWidget();
        taskTab->setObjectName(QString::fromUtf8("taskTab"));
        tabWidget->addTab(taskTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(contactTab), QCoreApplication::translate("MainWindow", "Contacts", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(taskTab), QCoreApplication::translate("MainWindow", "T\303\242ches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWVYBLBS_H
