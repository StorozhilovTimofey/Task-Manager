cmake_minimum_required(VERSION 3.11)

project(RAM)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/RAM.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)