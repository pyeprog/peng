add_library(catch_main STATIC catch_main.cpp)
target_include_directories(catch_main PUBLIC catch2)

add_executable(tests test_empty.cpp)
target_link_libraries(tests PRIVATE catch_main)
