cmake_minimum_required(VERSION 3.16)

project(QuadMesher LANGUAGES CXX VERSION 0.1)

include(cmake/StandardProjectSettings.cmake)

add_library(project_warning INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warning)

add_library(project_option INTERFACE)
target_compile_features(project_option INTERFACE cxx_std_17)

# third party
include(cmake/ExternFetcher.cmake)
git_extern_fetcher(pmp-library https://github.com/pmp-library/pmp-library.git 1.2.0)

add_executable(app src/main.cpp test/test_empty.cpp)

option(ENABLE_TESTING "Enable Test Builds" ON)
if (ENABLE_TESTING)
    enable_testing()
    message("Building Tests. Be sure to check out test/constexpr_tests for constexpr testing")
    add_subdirectory(test)
endif ()
