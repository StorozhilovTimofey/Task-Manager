cmake_minimum_required(VERSION 3.11)

project(GeneralRAM)

set(SOURCES
    src/main.cpp
    src/ControllerGeneralRAM.cpp
    src/ModelGeneralRAM.cpp
    src/ViewGeneralRAM.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)