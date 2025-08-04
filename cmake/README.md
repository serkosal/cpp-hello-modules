#

# requirements

gcc 15.0    or above
ninja 1.11  or above
cmake 3.28  or above

```bash
rm -rf build && mkdir build && cd build
cmake -G Ninja ..
ninja -j$(nproc)
```