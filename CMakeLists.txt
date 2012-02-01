cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME SpaceZ)

Project(${PROJECT_NAME})

set(
    SOURCES
    src/main.cpp
)

Find_Package(Allegro REQUIRED)

link_libraries (
    ${ALLEGRO_LIBRARIES}
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

