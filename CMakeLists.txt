cmake_minimum_required(VERSION 3.16)
project(ExQt2QML VERSION 0.1 LANGUAGES CXX)
include(res/config.cmake)
find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appExQt2QML
    main.cpp
    gearcontrollermanager.cpp
    gearcontrollermanager.h
    assets.qrc
)
qt_add_qml_module(appExQt2QML
    URI GearController
    VERSION 1.0
    QML_FILES
        SOURCES gearcontroller.h gearcontroller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appExQt2QML PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appExQt2QML
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appExQt2QML
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appExQt2QML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)



