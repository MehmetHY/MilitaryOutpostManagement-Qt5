cmake_minimum_required(VERSION 3.5)

project(MilitaryOutpostManagement VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)

set(PROJECT_SOURCES
        main.cpp

        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        Models/platoon.h
        Models/platoon.cpp

        Models/squad.h
        Models/squad.cpp

        Models/team.h
        Models/team.cpp

        Models/soldier.h
        Models/soldier.cpp

        Models/rank.h
        Models/rank.cpp

        Models/duty.h
        Models/duty.cpp

        Data/datamanager.h
        Data/datamanager.cpp

        Views/dutyview.h
        Views/dutyview.cpp
        Views/dutyview.ui

        Views/dashboard.h
        Views/dashboard.cpp
        Views/dashboard.ui

        Views/managesquadsview.h
        Views/managesquadsview.cpp
        Views/managesquadsview.ui

        Views/createsquadview.h
        Views/createsquadview.cpp
        Views/createsquadview.ui

        Views/deletesquadview.h
        Views/deletesquadview.cpp
        Views/deletesquadview.ui

        Views/updatesquadview.h
        Views/updatesquadview.cpp
        Views/updatesquadview.ui

        Views/manageteamsview.h
        Views/manageteamsview.cpp
        Views/manageteamsview.ui

        Views/createteamview.h
        Views/createteamview.cpp
        Views/createteamview.ui

        Views/deleteteamview.h
        Views/deleteteamview.cpp
        Views/deleteteamview.ui

        Views/updateteamview.h
        Views/updateteamview.cpp
        Views/updateteamview.ui

        Views/managesoldiersview.h
        Views/managesoldiersview.cpp
        Views/managesoldiersview.ui

        Views/createsoldierview.h
        Views/createsoldierview.cpp
        Views/createsoldierview.ui

        Views/deletesoldierview.h
        Views/deletesoldierview.cpp
        Views/deletesoldierview.ui

        Views/updatesoldierview.h
        Views/updatesoldierview.cpp
        Views/updatesoldierview.ui

        Views/manageranksview.h
        Views/manageranksview.cpp
        Views/manageranksview.ui

        Views/createrankview.h
        Views/createrankview.cpp
        Views/createrankview.ui

        Views/deleterankview.h
        Views/deleterankview.cpp
        Views/deleterankview.ui

        Views/updaterankview.h
        Views/updaterankview.cpp
        Views/updaterankview.ui

        Views/managedutiesview.h
        Views/managedutiesview.cpp
        Views/managedutiesview.ui

        Views/createdutyview.h
        Views/createdutyview.cpp
        Views/createdutyview.ui

        Views/deletedutyview.h
        Views/deletedutyview.cpp
        Views/deletedutyview.ui

        Views/updatedutyview.h
        Views/updatedutyview.cpp
        Views/updatedutyview.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MilitaryOutpostManagement
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MilitaryOutpostManagement APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MilitaryOutpostManagement SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MilitaryOutpostManagement
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MilitaryOutpostManagement PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(MilitaryOutpostManagement PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MilitaryOutpostManagement)
endif()
