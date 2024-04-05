cmake_minimum_required(VERSION 3.27)
project(homework1)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework1 main.cpp)
find_library(GMP gmp)
if(GMP)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${GMP})
endif()