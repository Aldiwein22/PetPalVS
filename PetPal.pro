QT += core gui widgets network quick

CONFIG += c++17

# Define project
TEMPLATE = app
TARGET = PetPal

# Add sources
SOURCES += \\
    src/Haustier.cpp \\
    src/GUI.cpp \\
    src/PetPal.cpp \\
    src/MainWindow.cpp \\
    src/MainScreen.cpp \\
    src/Pet.cpp \\
    src/WeatherAPI.cpp \\
    src/main.cpp

# Add headers
HEADERS += \\
    include/Haustier.h \\
    include/GUI.h \\
    include/PetPal.h \\
    include/MainWindow.h \\
    include/MainScreen.h \\
    include/Pet.h \\
    include/WeatherAPI.h

# Add qml files
RESOURCES += \\
    Main.qml \\
    Erstellungsbildschirm.qml \\
    Hauptbildschirm.qml \\
    Interaktionsbildschirm.qml \\
    WeatherAPI.qml

# Add additional include directories
INCLUDEPATH += include

# Add additional libraries
LIBS += -LC:/Qt/6.7.1/mingw_64/lib -lQt6Widgets -lQt6Network

# Specify compiler
QMAKE_CXXFLAGS += -std=gnu++17
