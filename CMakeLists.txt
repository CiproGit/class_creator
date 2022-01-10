cmake_minimum_required(VERSION 3.5)

project(class_creator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core REQUIRED)

include_directories(include)

if (UNIX)
    set(SOURCES src/main.cpp src/class_creator.cpp src/unix_os.cpp)
    set(HEADERS include/class_creator.h include/unix_os.h)
endif ()

if (WIN32)
    set(SOURCES src/main.cpp src/class_creator.cpp src/windows_os.cpp)
    set(HEADERS include/class_creator.h include/windows_os.h)
endif ()

add_executable(class_creator ${SOURCES} ${HEADERS})
target_link_libraries(class_creator Qt6::Core)
