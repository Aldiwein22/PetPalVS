cmake_minimum_required(VERSION 3.5)
project(PetPal LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "c:/Qt/6.7.1/mingw_64")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories(include)
aux_source_directory(./src SRCS)

set(PROJECT_SOURCES
        Haustier.h
        Haustier.cpp
        GUI.h
        GUI.cpp
        PetPal.h
        PetPal.cpp
        PetPal.ui
        MainWindow.h
        MainWindow.cpp
        MainWindow.ui
        MainScreen.h
        MainScreen.cpp
        MainScreen.ui
        Pet.h
        Pet.cpp
        main.cpp
)

add_executable(${PROJECT_NAME} WIN32 ${SRCS})

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
