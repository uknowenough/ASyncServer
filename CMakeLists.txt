cmake_minimum_required(VERSION 3.5)

project(AsyncServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost QUIET REQUIRED COMPONENTS program_options)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third-party/asio/asio/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(AsyncServer src/main.cpp src/Server.cpp include/Server.h)

target_link_libraries(AsyncServer PRIVATE Threads::Threads)
target_link_libraries(AsyncServer PUBLIC Boost::program_options)
