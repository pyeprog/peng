add_library(quadmesh placeholder.cpp)
include(algorithm/CMakeLists.txt)
include(model/CMakeLists.txt)
target_link_libraries(quadmesh PUBLIC pmp project_warning project_options)

target_include_directories(quadmesh PUBLIC pmp)

add_executable(playground playground.cpp)
target_link_libraries(playground PRIVATE quadmesh)

