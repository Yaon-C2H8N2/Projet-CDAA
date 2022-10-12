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
        REQUIRED)

add_executable(Projet_CDAA main.cpp src/Contact/Contact.cpp src/Contact/Contact.h src/Interaction/Interaction.cpp src/Interaction/Interaction.h src/GestionContact/GestionContact.cpp src/GestionContact/GestionContact.h)
target_link_libraries(Projet_CDAA
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

