// libmodule.cppm

module;

#include <iostream>

export module libmodule;

export void hello_world() {
    std::cout << "Hello, World!";
}