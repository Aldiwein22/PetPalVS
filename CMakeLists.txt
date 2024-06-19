cmake_minimum_required(VERSION 3.5)
project(PetPal LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Vulkan_INCLUDE_DIR "C:/VulkanSDK/1.3.283.0/Include")
set(CMAKE_PREFIX_PATH "C:/Qt/Tools/CMake_64/bin")
set(QT_DIR "C:/Qt/6.7.1/mingw_64/lib/cmake/Qt6")

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Network)
find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

include_directories(include)
aux_source_directory(./src SRCS)

set(PROJECT_SOURCES
        main.cpp
)

qt_add_executable(${PROJECT_NAME} WIN32 ${SRCS}
        C:/Users/Aldiwein/Desktop/PetPalVS/src/main.cpp
)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(SOURCES main.cpp)

qt_standard_project_setup(REQUIRES 6.5)

qt6_add_qml_module(${PROJECT_NAME}
    URI PetPal
    VERSION 1.0
    QML_FILES
        QML_FILES qml/Main.qml
        QML_FILES qml/Hauptbildschirm.qml
        QML_FILES qml/Erstellungsbildschirm.qml
        QML_FILES qml/Interaktionsbildschirm.qml
        QML_FILES qml/WeatherAPI.qml
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
)