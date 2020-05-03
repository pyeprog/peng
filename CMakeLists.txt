cmake_minimum_required(VERSION 3.16)

project(QuadMesher LANGUAGES CXX VERSION 0.1)

include(cmake/StandardProjectSettings.cmake)

add_library(project_warning INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warning)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# third party
include(ExternalProject)
ExternalProject_Add(pmp-library
        GIT_REPOSITORY https://github.com/pmp-library/pmp-library.git
        GIT_TAG 1.2.0
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/extern
        BINARY_DIR ${CMAKE_SOURCE_DIR}
        )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)


add_executable(app src/main.cpp test/test_empty.cpp)

option(ENABLE_TESTING "Enable Test Builds" ON)
if (ENABLE_TESTING)
    enable_testing()
    message("Building Tests. Be sure to check out test/constexpr_tests for constexpr testing")
    add_subdirectory(test)
endif ()
