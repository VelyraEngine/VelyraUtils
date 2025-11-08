# VelyraUtils
## Build Status:
- ** Ubuntu (GCC)**: ![Ubuntu Build](https://github.com/VelyraEngine/VelyraUtils/actions/workflows/main.yml/badge.svg?branch=main&job=build-ubuntu)
- ** Windows (MSVC)**: ![Windows Build](https://github.com/VelyraEngine/VelyraUtils/actions/workflows/main.yml/badge.svg?branch=main&job=build-windows)

C++ utils for Velyra projects.

## Installation
### Ubuntu 20.04
Install the necessary packages
```shell
sudo apt install gcc g++ cmake git
```
To enjoy faster builds, consider installing the following packages as well.
```shell
sudo apt install ninja-build ccache mold
```

### Windows 11
Install MSVC using the installer found on the microsoft webpage.

## Build
The project is build with CMake, optional flags:

- `BUILD_TESTING`: When set to =ON, unit tests are build.