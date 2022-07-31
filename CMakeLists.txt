cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "")

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")
endif()

# Conan setup
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
set(CMAKE_FIND_ROOT_PATH ${CONAN_CMAKE_MODULE_PATH})

# Project settings
project(BuildAndReleaseTest LANGUAGES CXX)

set(COMMON_WARNINGS
    -Wall
    -Wextra # reasonable and standard
    -Wunused # warn on anything being unused
    -Wno-unused-parameter
    -Wno-deprecated-declarations
    -Wpedantic # warn if non-standard C++ is used
)
set(_warning_flags "${COMMON_WARNINGS}")  
option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
if (WARNINGS_AS_ERRORS)
    list(APPEND _warning_flags "-Werror")
endif()
add_compile_options("$<$<COMPILE_LANGUAGE:${LANGUAGE}>:${_warning_flags}>")

include(cmake/build_system.cmake)

add_subdirectory(src)

include(CTest)
enable_testing()
add_subdirectory(test)
