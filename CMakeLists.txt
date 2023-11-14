cmake_minimum_required(VERSION 3.5)

project(class_creator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Add build directory to include path

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

include_directories(include)

# Settings for Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SOURCES src/main.cpp src/class_creator.cpp src/windows_os.cpp)
    set(HEADERS include/class_creator.h include/windows_os.h)

    add_compile_definitions(APP_NAME="${PROJECT_NAME}") # Name in Windows properties
    configure_file(version.rc.in version.rc) # Set VERSIONINFO file

    # Set Windows resources
    enable_language("RC")
    set(WIN32_RESOURCES ${PROJECT_BINARY_DIR}/version.rc)
endif()

# Settings for Mac OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(SOURCES src/main.cpp src/class_creator.cpp src/unix_os.cpp)
    set(HEADERS include/class_creator.h include/unix_os.h)

    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0") # Set minimum target to Mac OS Big Sur
endif()

# Settings for Linux
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(SOURCES src/main.cpp src/class_creator.cpp src/unix_os.cpp)
    set(HEADERS include/class_creator.h include/unix_os.h)
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${WIN32_RESOURCES})

configure_file(config.h.in config.h) # Set config header file

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
