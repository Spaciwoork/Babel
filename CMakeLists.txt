project(CPP_babel_2021)
cmake_minimum_required(VERSION 3.9)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

include(${CMAKE_BINARY_DIR}/../build/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets REQUIRED)

find_package(Qt5Core)
find_package(Qt5Network)

include_directories(server/include)
include_directories(server/src)

file(GLOB_RECURSE SERVER_INCLUDE_FILES server/include/*.hpp)
file(GLOB_RECURSE SERVER_SOURCE_FILES server/src/*.cpp)

add_executable(babel_client ../client/src/main ../client/src/CreateWindow.cpp client/src/QuitButton.cpp client/include/QuitButton.hpp client/src/CustomWidget.cpp client/include/CustomWidget.hpp client/src/ListeUsers.cpp client/include/ListeUsers.hpp client/src/Connection.cpp client/include/Connection.hpp client/src/AddUserButton.cpp client/include/AddUserButton.hpp client/src/Network.cpp client/include/Network.hpp client/src/ClientServer.cpp client/include/ClientServer.hpp client/src/clientconnect.cpp client/include/clientconnect.hpp client/src/audio.cpp client/include/audio.hpp client/src/serverconnect.cpp client/include/serverconnect.hpp client/src/Caller.cpp client/include/Caller.hpp)
target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Core Qt5::Network)

add_executable(babel_server ${SERVER_SOURCE_FILES} ${SERVER_INCLUDE_FILES})
target_link_libraries(babel_server ${CONAN_LIBS})
