# Contributing

project maintained by [**SalaxDev**](https://github.com/SalaxDev). PRs welcome, but please open an issue first.

## Build

Requires:
- <GCC 13 / Clang 17>, CMake ≥ 3.19. <br>
-  SDL3 3.4.20 or higher <br>
-  SDL3_ttf 3.2.xx or higher <br>
-  SDL3_image 3.4.xx or higher <br>
-  SDL3_mixer 3.2.xx or higher <br>

## Terminal
```bash
git clone <repo-url>
cd <repo>
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
```

## Test
```bash
ctest --test-dir build --output-on-failure
```

One change per PR, squash-merged.

Bug reports: compiler + version, OS, minimal repro, full error output.

By contributing you agree your work is **MIT-licensed** (see [LICENSE](LICENSE.txt)).
