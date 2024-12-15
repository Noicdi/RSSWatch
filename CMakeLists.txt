cmake_minimum_required(VERSION 3.21)

project(RSSWatch VERSION 0.0.1)

add_executable(${PROJECT_NAME} 
        src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)
