file(GLOB MODEL_SOURCES *.cpp)
file(GLOB MODEL_HEADERS *.h)
install(FILES ${MODEL_HEADERS} DESTINATION include/quadmesh/model)

target_sources(quadmesh PRIVATE ${MODEL_SOURCES})
target_include_directories(quadmesh PUBLIC .)