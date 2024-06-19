QT += core gui widgets network quick

CONFIG += c++17

# Define project
TEMPLATE = app
TARGET = PetPal

# Add sources
SOURCES += \\
    src/main.cpp

# Add headers
HEADERS += \\
    include/

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
