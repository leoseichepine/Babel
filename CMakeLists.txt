project(Babel)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_GENERATOR_PLATFORM "x64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB DLLS "${CMAKE_SOURCE_DIR}/dll/*.dll")

if(WIN_32)
    file(COPY ${DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
endif()

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message("The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    message(STATUS "Boost Found : Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
endif()

include_directories(${CMAKE_INCLUDE_PATH})

set(SRCS_SERVER
        src/common/network/ConnectionInfos.cpp
        src/common/network/ATCPSocket.cpp
        src/common/sound/AudioCodec/OpusCodec.cpp
        src/common/sound/AudioLibrary/PortAudioLibrary.cpp
        src/common/threads/Mutex.cpp
        src/common/threads/ScopedLock.cpp
        src/common/network/BoostTCPSocket.cpp
        src/common/commandParser/CommandParser.cpp
        src/common/commandParser/Data.cpp
        src/server/db/Database.cpp
        src/server/db/User.cpp
        src/server/Server.cpp
        src/server/main.cpp
        )

set(HEADERS_SERVER
        src/common/exception/BabelException.hpp
        src/common/network/ConnectionInfos.hpp
        src/common/network/ATCPSocket.hpp
        src/common/network/BoostTCPSocket.hpp
        src/common/sound/AudioCodec/IAudioCodec.hpp
        src/common/sound/AudioCodec/OpusCodec.hpp
        src/common/sound/AudioLibrary/IAudioLibrary.hpp
        src/common/sound/AudioLibrary/PortAudioLibrary.hpp
        src/common/commandParser/CommandParser.hpp
        src/server/db/Database.hpp
        src/server/db/User.hpp
        src/common/commandParser/Data.hpp
        src/server/Server.hpp
        )

set(SRCS_CLIENT
        src/client/main.cpp
        src/client/MainWindow.cpp
        src/client/login/ConnectionWidget.cpp
        src/client/login/RegisterWidget.cpp
        src/client/login/LoginWidget.cpp
        src/client/contactList/ContactList.cpp
        src/client/stateMachine/AState.cpp
        src/common/network/ATCPSocket.cpp
        src/client/network/TCPClient.cpp
        src/client/network/QtTCPSocket.cpp
        src/common/network/ConnectionInfos.cpp
        src/common/commandParser/CommandParser.cpp
        src/common/commandParser/Data.cpp
        )

set(HEADERS_CLIENT
        src/client/MainWindow.hpp
        src/client/stateMachine/AState.hpp
        src/client/login/ConnectionWidget.hpp
        src/client/login/RegisterWidget.hpp
        src/client/stateMachine/AState.hpp
        src/client/login/LoginWidget.hpp
        src/client/contactList/ContactList.hpp
        src/client/network/TCPClient.hpp
        src/common/network/ATCPSocket.hpp
        src/client/network/QtTCPSocket.hpp
        src/common/network/ConnectionInfos.hpp
        src/common/commandParser/CommandParser.hpp
        src/common/commandParser/Data.hpp
        )

qt5_wrap_cpp(
    client_head
    ./src/client/login/ConnectionWidget.hpp
    ./src/client/login/RegisterWidget.hpp
    ./src/client/login/LoginWidget.hpp
    ./src/client/MainWindow.hpp
    ./src/client/stateMachine/AState.hpp
    ./src/client/contactList/ContactList.hpp
    ./src/common/network/ATCPSocket.hpp
    ./src/common/network/ConnectionInfos.hpp
    ./src/client/network/QtTCPSocket.hpp
    )

qt5_wrap_ui(
    client_ui ./src/client/login/LoginWidget.ui
    )

add_executable(babel_server ${SRCS_SERVER} ${HEADERS_SERVER})
add_executable(babel_client ${SRCS_CLIENT} ${client_ui} ${client_head})

target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets)
target_link_libraries(babel_server ${CONAN_LIBS} Qt5::Widgets)
target_link_libraries(babel_server ${Boost_LIBRARIES})
target_link_libraries(babel_client ${Boost_LIBRARIES})
target_link_libraries(babel_client Qt5::Network)

if(WIN32)
    target_link_libraries(babel_server wsock32 ws2_32)
    target_link_libraries(babel_client wsock32 ws2_32)
endif()
