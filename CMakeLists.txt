cmake_minimum_required(VERSION 3.21)

project(RSSWatch VERSION 0.0.1)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ConfFile.cpp
    src/Config.cpp
    src/Common.cpp
    src/EventLoop.cpp
    src/HttpServer.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

find_package(spdlog CONFIG REQUIRED)
if(NOT spdlog_FOUND)
    message(FATAL_ERROR "spdlog library is required but was not found. Ensure it is installed via vcpkg or your package manager.")
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

find_package(Libevent CONFIG REQUIRED)
if(NOT Libevent_FOUND)
    message(FATAL_ERROR "Libevent library is required but was not found. Ensure it is installed via vcpkg or your package manager.")
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE libevent::core libevent::extra)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)
