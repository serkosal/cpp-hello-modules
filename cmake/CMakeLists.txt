cmake_minimum_required(VERSION 3.29.20240416 FATAL_ERROR)


if (NOT CMAKE_GENERATOR STREQUAL "Ninja")
    message(FATAL_ERROR "This project requires the Ninja generator. Refers to https://cmake.org/cmake/help/latest/manual/cmake-cxxmodules.7.html#generator-support")
endif ()


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# !!!!!!!!!!!!!!!!!!!!!!!!!  SET UUID FOR YOUR CMAKE VERSION HERE!
#                                               |
#                                               v
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

# Tell CMake that we explicitly want `import std`. This will initialize the
# property on all targets declared after this to 1
set(CMAKE_CXX_MODULE_STD 1)

# C++ needs to be enabled.
project(cmake_modules LANGUAGES CXX)

# Make an executable.
add_executable(main main.cpp)
# target_link_libraries(main PRIVATE libmobule)
target_sources(
    main PRIVATE
    FILE_SET modules TYPE CXX_MODULES
    BASE_DIRS . 
    FILES libmodule.cppm 
)