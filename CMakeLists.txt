cmake_minimum_required(VERSION 2.8.9)

project (postsvr)

add_executable(postsvr postsvr.cpp)

target_link_libraries(postsvr
    curl
)