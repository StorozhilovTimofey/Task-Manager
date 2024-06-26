cmake_minimum_required(VERSION 3.5)

project(Tasks-Manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
		main.cpp
		Model/ModelData.cpp
        Model/Model.cpp
		View/ViewData.cpp
        View/View.cpp
		Controller/ControllerData.cpp
        Controller/Controller.cpp
)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Tasks-Manager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(Tasks-Manager SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Tasks-Manager
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_include_directories(Tasks-Manager PRIVATE
		${PROJECT_SOURCE_DIR}/Controller
		${PROJECT_SOURCE_DIR}/Model
		${PROJECT_SOURCE_DIR}/View
)


target_link_libraries(Tasks-Manager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Tasks-Manager PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Tasks-Manager)
endif()
