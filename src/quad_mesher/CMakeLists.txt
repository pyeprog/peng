add_executable(app main.cpp)

get_target_property(PMP_INCLUDE_DIR pmp INCLUDE_DIRECTORIES)
target_link_libraries(app PRIVATE pmp)
target_include_directories(app PRIVATE ${PMP_INCLUDE_DIR})
