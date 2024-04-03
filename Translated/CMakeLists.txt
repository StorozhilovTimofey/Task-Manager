cmake_minimum_required(VERSION 3.11)
project(GeneralRAMParams VERSION 1.0)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/Controller.cpp
    src/ControllerGRAM.cpp
    src/main.cpp
    src/ModelGRAM.cpp
    src/ViewGRAM.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/headers
        ${PROJECT_SOURCE_DIR}/interfaces
)