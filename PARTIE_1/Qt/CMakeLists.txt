cmake_minimum_required(VERSION 3.14)

project(PARTIE_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Gui REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

SET(SRC
    src/main.cpp
)

SET(HEADERS
	
)
add_executable(Main ${SRC} ${HEADERS})
target_link_libraries(Main Qt5::Core Qt5::Gui)
