#! /usr/bin/sh

conan install . -if ./build
cmake --preset default
cmake --build --preset default