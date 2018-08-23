# Simple-Serialization

Lightweight C++ library for binary serialization

## Features

This project provides space-saving serialization and deserialization using `std::ostream` and `std::istream` instances.

Explicitly provided classes:
* `std::map<Key, T>`
* `std::optional<T>`
* `std::pair<T1, T2>`
* `std::string`
* `std::vector`

## Manual

This project uses the **C++17** standard. Its entire implementation resides in header files.

### Usage

For general use, `#include` the [`serialization.h`](../tree/master/include/simple-serialization/serialization.h) file into your project.

### Testing

In order to run the unit-tests, you need to compile the contents of the [`test/`](../tree/master/test) directory to an executable. Make sure to have the test framework [*Catch2*](https://github.com/catchorg/Catch2) installed.
