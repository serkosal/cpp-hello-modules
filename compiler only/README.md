# Compiler only example

This folder contains example of compile and linking module file
into executable file.

# requirements

- gcc 14.0 or above

# build

## build module files

```bash
# compile module file
g++ -std=c++20 -fmodules -c hello_world.cppm -o hello_world.o
```

flag `-c`, specify that we need only to compile file, avoid linking stage

```bash
g++ -std=c++20 -fmodules -c main.cpp -o main.o  # compile main.cpp file
g++ hello_world.o main.o -o hello_app.out       # link them all in one executable
```