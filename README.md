Boilerplate for TDD on ESP32
============================
[![CircleCI](https://circleci.com/gh/kien-company/esp32-tdd-boilerplate.svg?style=svg)](https://circleci.com/gh/kien-company/esp32-tdd-boilerplate)

This repo contains a boilerplate that demonstrates how to do TDD and CI with the ESP32.

## Setting up the environment
1. Install [ESP32 toolchain](https://esp-idf.readthedocs.io/en/latest/get-started/index.html#setup-toolchain)
2. Install [ESP-IDF 3.1.1](https://esp-idf.readthedocs.io/en/latest/get-started/index.html#get-esp-idf)
    1. Clone the repo (`git clone git@github.com:espressif/esp-idf.git`)
    2. Checkout to version v3.1 (`git checkout v3.1.1`)
    3. Update submodules (`git submodule update --init --recursive`)
3. Create a file called `Makefile.local` in the project root with the following content:
```
IDF_PATH := /absolute/path/to/your/esp-idf
```

## Compile and flash the target
* To compile the project run `make all`
* To flash the target run `make flash`

## Compile and run the unit tests
*Note: instructions are for Linux. It should be compatible with other OS, but it has not been tested*
* Setup the environment with `mkdir -p build/test` and `cmake ..`
* Run the tests with `make all test`. If a test fails, more details can be get by running `./tdd`

## Static analysis
The most simple option relies on [cppcheck](cppcheck.sourceforge.net). To perform the analysis run `cppcheck --template=gcc --enable=style main/`.

## EXTRA: Code style
To keep a common coding style, the files that have been modified shall be formatted before committing them using `clang-format`. To use it follow these steps:
1. Install `clang-format`
2. Run `clang-format -i -style=file [file.X]`
Note. Many IDEs allow to do this automatically, check in the Preferences or in the avaiable Plugins.

There is also available a config file for [EditorConfig](https://editorconfig.org). Make sure you install that in your IDE.

## License
This repository is released under the MIT license. Please refer to the LICENSE file.
