add_library(quadmesh placeholder.cpp)
target_include_directories(quadmesh PUBLIC model)
target_link_libraries(quadmesh PUBLIC pmp project_warning project_options)
get_target_property(PMP_INCLUDE_DIR pmp INCLUDE_DIRECTORIES)
target_include_directories(quadmesh PUBLIC ${PMP_INCLUDE_DIR})

add_executable(playground playground.cpp model/coordinate.h)
target_link_libraries(playground PRIVATE quadmesh)

