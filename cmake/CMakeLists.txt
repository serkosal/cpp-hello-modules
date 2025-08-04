cmake_minimum_required(VERSION 4.0.0)

project(cmake_modules VERSION 0.1.0 LANGUAGES CXX)

if (NOT CMAKE_GENERATOR STREQUAL "Ninja")
    message(FATAL_ERROR "This project requires the Ninja generator. Refers to https://cmake.org/cmake/help/latest/manual/cmake-cxxmodules.7.html#generator-support")
endif ()


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")


add_executable(cmake_modules main.cpp libmodule.cppm)

target_sources(
    cmake_modules PRIVATE
    FILE_SET modules TYPE CXX_MODULES
    BASE_DIRS . 
    FILES libmodule.cppm 
)


target_compile_options(
    cmake_modules PRIVATE 
    -fmodules-ts
)