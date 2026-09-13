cmake_minimum_required(VERSION 3.20)
project(hash-vectors VERSION 0.1.0 LANGUAGES CXX)
include(cmake/BuildConfig.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# repo-build-cfg-all
if(WIN32)
  add_custom_target(_repo_build_cfg ALL
    COMMAND "${CMAKE_SOURCE_DIR}/msbuild/run.cmd"
    VERBATIM)
endif()
