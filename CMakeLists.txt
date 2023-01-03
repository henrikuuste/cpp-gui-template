cmake_minimum_required(VERSION 3.15)
project(cpp-gui LANGUAGES CXX)

enable_testing()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(ENABLE_DEVELOPER_MODE
    TRUE
    CACHE BOOL "Enable developer mode (sanitizers, clang-tidy etc)")
include(project_options)
include(conan_setup)

add_subdirectory(src)
# add_subdirectory(test)
