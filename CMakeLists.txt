cmake_minimum_required(VERSION 3.18)

project(aes-128)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -g -w")

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/tiny-AES-c
)

file(GLOB aes_SRC
    ${CMAKE_SOURCE_DIR}/lib/tiny-AES-c/*.c
)

set(SOURCES
    ${aes_SRC}
)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp ${SOURCES})


