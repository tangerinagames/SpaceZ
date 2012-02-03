cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME SpaceZ)

Project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(
    SOURCES
    src/main.cpp
    src/Ship.cpp
)

Find_Package(Allegro REQUIRED)

link_libraries (
    ${ALLEGRO_LIBRARIES}
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

