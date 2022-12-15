QT       += core gui widgets sql

TARGET = projetCDAA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
	src/Contact/Contact.cpp \
	src/Interaction/Interaction.cpp \
	src/GestionContact/GestionContact.cpp \
	src/Tache/Tache.cpp \
	src/GestionTache/GestionTache.cpp \
	src/GestionInteraction/GestionInteraction.cpp \
	src/GUI/MainWindow/MainWindow.cpp \
	src/GUI/ContactList/ContactList.cpp \
	src/GUI/TasksList/TasksList.cpp \
	src/GUI/ContactInfo/ContactInfo.cpp \
	src/GUI/ContactButton/ContactButton.cpp \
	src/GUI/ContactCreator/ContactCreator.cpp \
	src/GUI/ContactModifier/ContactModifier.cpp \
	src/InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.cpp \
	src/GUI/InteractionViewer/InteractionViewer.cpp \
	src/InterfaceJSON/InterfaceJSON.cpp

HEADERS += \
	src/Contact/Contact.h \
	src/Interaction/Interaction.h \
	src/GestionContact/GestionContact.h \
	src/Tache/Tache.h \
	src/GestionTache/GestionTache.h \
	src/GestionInteraction/GestionInteraction.h \
	src/GUI/MainWindow/MainWindow.h \
	src/GUI/ContactList/ContactList.h \
	src/GUI/TasksList/TasksList.h \
	src/GUI/ContactInfo/ContactInfo.h \
	src/GUI/ContactButton/ContactButton.h \
	src/GUI/ContactCreator/ContactCreator.h \
    src/GUI/ContactModifier/ContactModifier.h \
    src/InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.h \
    src/GUI/InteractionViewer/InteractionViewer.h \
    src/InterfaceJSON/InterfaceJSON.h \
    src/GUI/TasksList/ui_TasksList.h \
    src/GUI/ContactModifier/ui_ContactModifier.h \
    src/GUI/MainWindow/ui_MainWindow.h \
    src/GUI/ContactInfo/ui_ContactInfo.h \
    src/GUI/ContactInfo/ui_InteractionCreator.h \
    src/GUI/ContactList/ui_ContactDeleteDialog.h \
    src/GUI/ContactList/ui_ContactList.h \
    src/GUI/InteractionViewer/ui_InteractionViewer.h \
    src/GUI/ContactCreator/ui_ContactCreator.h


FORMS += \
    src/GUI/TasksList/TasksList.ui \
    src/GUI/ContactModifier/ContactModifier.ui \
    src/GUI/MainWindow/MainWindow.ui \
    src/GUI/ContactInfo/ContactInfo.ui \
    src/GUI/ContactInfo/InteractionCreator.ui \
    src/GUI/ContactList/ContactDeleteDialog.ui \
    src/GUI/ContactList/ContactList.ui \
    src/GUI/InteractionViewer/InteractionViewer.ui \
    src/GUI/ContactCreator/ContactCreator.ui