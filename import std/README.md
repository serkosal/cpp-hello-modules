# importing std

# requirements
GCC version above 15.0

# build

```bash
# compile iostream header file
g++ -std=c++23 -fmodules-ts -x c++-system-header iostream

# compile main.cpp file into executable
g++ -std=c++23 -v -fmodules-ts main.cpp -o main
```

# check time 
use flag `-ftime-report` for benchmark compilation time

g++ -std=c++23 -ftime-report -fmodules-ts main.cpp -o main

# benchmarks

## without modules

without iostream compiling:
| Time variable                       |        wall     |      GGC      |
| ----------------------------------- | --------------- | ------------- |
| phase setup                         |    0.02 (  1%)  |  1824k (  1%) |
| phase parsing                       |    0.69 ( 59%)  |    82M ( 68%) |
| phase lang. deferred                |    0.45 ( 38%)  |    35M ( 29%) |
| phase opt and generate              |    0.02 (  2%)  |  1301k (  1%) |
| |name lookup                        |    0.09 (  7%)  |  3508k (  3%) |
| |overload resolution                |    0.29 ( 24%)  |    20M ( 17%) |
| callgraph construction              |    0.01 (  1%)  |  1234k (  1%) |
| preprocessing                       |    0.12 ( 10%)  |  3831k (  3%) |
| parser (global)                     |    0.13 ( 11%)  |    27M ( 22%) |
| parser struct body                  |    0.12 ( 10%)  |    14M ( 12%) |
| parser function body                |    0.03 (  3%)  |  1845k (  1%) |
| parser inl. func. body              |    0.06 (  5%)  |  5863k (  5%) |
| parser inl. meth. body              |    0.11 (  9%)  |    13M ( 11%) |
| template instantiation              |    0.46 ( 39%)  |    43M ( 36%) |
| constant expression evaluation      |    0.03 (  3%)  |   771k (  1%) |
| constraint normalization            |    0.01 (  1%)  |   635k (  1%) |
| constraint satisfaction             |    0.07 (  6%)  |  5599k (  5%) |
| initialize rtl                      |    0.01 (  1%)  |    12k (  0%) |
| TOTAL                               |    1.19         |   120M        |

## after iostream module compile

| Time variable                      |     wall      |     GGC      |
| ---------------------------------- | ------------- | ------------ |
| phase setup                        |   0.02 ( 13%) | 1824k (  6%) |
| phase parsing                      |   0.09 ( 77%) |   25M ( 92%) |
| phase opt and generate             |   0.01 (  9%) |  250k (  1%) |
| |name lookup                       |   0.07 ( 61%) |   19M ( 72%) |
| |overload resolution               |   0.01 ( 12%) | 3905k ( 14%) |
| parser (global)                    |   0.01 (  8%) | 2226k (  8%) |
| parser function body               |   0.07 ( 60%) |   20M ( 72%) |
| template instantiation             |   0.01 ( 10%) | 3539k ( 12%) |
| **module import**                  |**0.09 ( 75%)**|**25M ( 91%)**|
| initialize rtl                     |   0.01 (  5%) |   12k (  0%) |
| TOTAL                              |   0.12        |   27M        |