# Compiler only example

This folder contains example of compile and linking module file
into executable file.

# requirements

- gcc 14.0 or above
- c++20 and above

# build

```bash
# compile module file into object file
g++ -std=c++20 -fmodules -c hello_world.cppm -o hello_world.o

# compile main.cpp file into object file
# flag `-c` specifies that we need only to compile file, avoid linking stage
g++ -std=c++20 -fmodules -c main.cpp -o main.o

# link all ours object files in one executable
g++ -std=c++20 -fmodules hello_world.o main.o -o hello_app.out  
```
