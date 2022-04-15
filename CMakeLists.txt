cmake_minimum_required(VERSION 3.5)

project(AsyncServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third-party/asio/asio/include)
message(${CMAKE_CURRENT_SOURCE_DIR}/third-party/asio/asio/include)

add_executable(AsyncServer src/main.cpp)
