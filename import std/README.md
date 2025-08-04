# importing std

# requirements
GCC version above 15.0

# build;
```bash
# one liner build, but it builds std module every time
g++ -std=c++23 -fmodules-ts -fsearch-include-path bits/std.cc main.cpp -o main.out

# separate build
# build std module once
g++ -std=c++23 -fmodules-ts -fmodule-only -x c++ -c $(dirname $(which gcc))/../include/c++/15.1.0/bits/std.cc

# then gcc automatically will find builded files in directory `gcm.cache`
g++ -std=c++23 -fmodules-ts main.cpp -o main.out
```

# benchmark

## without modules

```bash
echo "
#include <bits/stdc++.h>

int main() { 
    std::cout << \"Hello, world!\\n\";
}" | \
g++ -x c++ -std=c++23 -ftime-report -
```

|           Time variable             |      wall     |      GGC     |
| ----------------------------------- | ------------- | ------------ |
|  phase setup                        |   0.01 (  0%) | 1813k (  1%) |
|  phase parsing                      |   2.29 ( 77%) |  273M ( 83%) |
|  phase lang. deferred               |   0.64 ( 21%) |   50M ( 15%) |
|  phase opt and generate             |   0.04 (  1%) | 2218k (  1%) |
|  |name lookup                       |   0.28 (  9%) | 9625k (  3%) |
|  |overload resolution               |   0.56 ( 19%) |   39M ( 12%) |
|  callgraph construction             |   0.03 (  1%) | 2146k (  1%) |
|  preprocessing                      |   0.31 ( 10%) |   14M (  4%) |
|  parser (global)                    |   0.36 ( 12%) |   95M ( 29%) |
|  parser struct body                 |   0.40 ( 14%) |   44M ( 13%) |
|  parser function body               |   0.15 (  5%) | 8764k (  3%) |
|  parser inl. func. body             |   0.18 (  6%) |   11M (  3%) |
|  parser inl. meth. body             |   0.45 ( 15%) |   45M ( 14%) |
|  template instantiation             |   0.91 ( 31%) |   95M ( 29%) |
|  constant expression evaluation     |   0.06 (  2%) | 1123k (  0%) |
|  constraint normalization           |   0.01 (  0%) |  832k (  0%) |
|  constraint satisfaction            |   0.10 (  3%) | 7040k (  2%) |
|  initialize rtl                     |   0.01 (  0%) |   12k (  0%) |
|  TOTAL                              |   2.98        |  328M        |

## using modules

```bash
g++ -std=c++23 -fmodules-ts -ftime-report -fsearch-include-path bits/std.cc main.cpp -o main.out
```

### module export with it's rebuilding
|           Time variable             |      wall     |      GGC     |
| ----------------------------------- | ------------- | ------------ |
|  phase setup                        |   0.01 (  0%) | 1824k (  1%) |
|  phase parsing                      |   2.27 ( 41%) |  282M ( 83%) |
|  phase lang. deferred               |   3.24 ( 58%) |   52M ( 15%) |
|  phase opt and generate             |   0.04 (  1%) | 2212k (  1%) |
|  |name lookup                       |   0.30 (  5%) |   11M (  3%) |
|  |overload resolution               |   0.55 ( 10%) |   41M ( 12%) |
|  callgraph construction             |   0.03 (  1%) | 2148k (  1%) |
|  preprocessing                      |   0.31 (  6%) |   14M (  4%) |
|  parser (global)                    |   2.95 ( 53%) |  100M ( 30%) |
|  parser struct body                 |   0.39 (  7%) |   44M ( 13%) |
|  parser function body               |   0.18 (  3%) |   11M (  3%) |
|  parser inl. func. body             |   0.17 (  3%) |   11M (  3%) |
|  parser inl. meth. body             |   0.43 (  8%) |   46M ( 14%) |
|  template instantiation             |   0.91 ( 16%) |   97M ( 29%) |
|  constant expression evaluation     |   0.06 (  1%) | 1123k (  0%) |
|  constraint normalization           |   0.01 (  0%) |  832k (  0%) |
|  constraint satisfaction            |   0.10 (  2%) | 6930k (  2%) |
|  **module export**                 |**2.58 ( 46%)**|**217k (  0%)**|
|  initialize rtl                     |   0.01 (  0%) |   12k (  0%) |
|  TOTAL                              |   5.56        |  339M        |

|           Time variable             |      wall     |      GGC     |
| ----------------------------------- | ------------- | ------------ |
|  phase setup                        |   0.01 (  2%) | 1824k (  2%) |
|  phase parsing                      |   0.27 ( 90%) |   90M ( 97%) |
|  phase lang. deferred               |   0.01 (  2%) |  143k (  0%) |
|  phase opt and generate             |   0.02 (  6%) |  764k (  1%) |
|  |name lookup                       |   0.21 ( 70%) |   71M ( 77%) |
|  |overload resolution               |   0.06 ( 19%) |   15M ( 17%) |
|  callgraph construction             |   0.01 (  3%) |  697k (  1%) |
|  parser (global)                    |   0.02 (  5%) | 4941k (  5%) |
|  parser function body               |   0.21 ( 68%) |   69M ( 75%) |
|  template instantiation             |   0.06 ( 19%) |   15M ( 17%) |
|**module import**                   |**0.27 ( 90%)** |**90M ( 97%)**|
|  initialize rtl                     |   0.01 (  2%) |   12k (  0%) |
|  TOTAL                              |   0.30        |   93M        |