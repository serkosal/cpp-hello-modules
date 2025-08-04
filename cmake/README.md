# requirements

- gcc 15.0    or above
- ninja 1.11  or above
- cmake 3.30  or above

set experemtal **UUID** for std modules support:
1.  look for your **version of CMake**:
    ```bash
    cmake --version
    ```
2.  go to the https://github.com/Kitware/CMake and choose **your version** in tags.
    *Tags* could be find at *branch selection*, click *master* right above repo's title
    and then choose *tag* corresponding to *your CMake version*.

3.  open file `Help/dev/experimental.rst` and copy *UUID value* from
    `C++ import std support` section.

4.  replace *UUID* in `CMakeLists.txt` file line `15`

# build

```bash
rm -rf build && mkdir build && cd build
cmake -G Ninja ..
ninja -j$(nproc)
```