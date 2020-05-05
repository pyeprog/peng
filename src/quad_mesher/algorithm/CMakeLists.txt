file(GLOB ALG_SOURCES *.cpp)
file(GLOB ALG_HEADERS *.h)
install(FILES ${ALG_HEADERS} DESTINATION include/quadmesh/algorithms)

target_sources(quadmesh PRIVATE ${ALG_SOURCES})
target_include_directories(quadmesh PUBLIC .)