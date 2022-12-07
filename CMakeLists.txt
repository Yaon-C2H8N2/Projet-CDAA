cmake_minimum_required(VERSION 3.23)
project(Projet_CDAA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(Projet_CDAA main.cpp src/Contact/Contact.cpp src/Contact/Contact.h src/Interaction/Interaction.cpp src/Interaction/Interaction.h src/GestionContact/GestionContact.h src/GestionContact/GestionContact.cpp src/Tache/Tache.cpp src/Tache/Tache.h src/GestionTache/GestionTache.cpp src/GestionTache/GestionTache.h src/GestionInteraction/GestionInteraction.cpp src/GestionInteraction/GestionInteraction.h src/GUI/MainWindow/MainWindow.cpp src/GUI/MainWindow/MainWindow.h src/GUI/ContactList/ContactList.cpp src/GUI/ContactList/ContactList.h src/GUI/TasksList/TasksList.cpp src/GUI/TasksList/TasksList.h src/GUI/ContactInfo/ContactInfo.cpp src/GUI/ContactInfo/ContactInfo.h src/GUI/ContactButton/ContactButton.cpp src/GUI/ContactButton/ContactButton.h src/GUI/ContactCreator/ContactCreator.cpp src/GUI/ContactCreator/ContactCreator.h src/GUI/ContactModifier/ContactModifier.cpp src/GUI/ContactModifier/ContactModifier.h src/InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.cpp src/InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.h src/GUI/InteractionViewer/InteractionViewer.cpp src/GUI/InteractionViewer/InteractionViewer.h)
target_link_libraries(Projet_CDAA
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        )
