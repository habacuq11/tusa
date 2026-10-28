cmake_minimum_required(VERSION 3.16)
project(tusa)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.cc"
    "${CMAKE_SOURCE_DIR}/src/*.cxx"
)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.h"
    "${CMAKE_SOURCE_DIR}/src/*.hpp"
)

file(GLOB_RECURSE RESOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.qrc"
)

file(GLOB_RECURSE UI_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.ui"
)

# Crear el ejecutable con todo lo de src/
add_executable(tusa
    ${SOURCES}
    ${HEADERS}
    ${RESOURCES}
    ${UI_FILES}
)

target_include_directories(tusa PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)

target_link_libraries(tusa PRIVATE
     Qt6::Multimedia
     Qt6::Widgets
    )