/********************************************************************************
** Form generated from reading UI file 'MainWindowNCrgAa.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWNCRGAA_H
#define MAINWINDOWNCRGAA_H

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
    QWidget *calendarTab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
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

        tabWidget->addTab(contactTab, QString());
        calendarTab = new QWidget();
        calendarTab->setObjectName(QString::fromUtf8("calendarTab"));
        tabWidget->addTab(calendarTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 24));
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
        tabWidget->setTabText(tabWidget->indexOf(calendarTab), QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWNCRGAA_H
