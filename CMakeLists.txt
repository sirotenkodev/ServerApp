cmake_minimum_required(VERSION 3.14)

project(ServerApp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ServerApp main.cpp httplib.h)

file(COPY ${PROJECT_SOURCE_DIR}/public DESTINATION ${PROJECT_BINARY_DIR})
