function(git_extern_fetcher NAME URL TAG)
    include(ExternalProject)
    ExternalProject_Add(${NAME}
            GIT_REPOSITORY ${URL}
            GIT_TAG ${TAG}
            SOURCE_DIR ${CMAKE_SOURCE_DIR}/extern/${NAME}
            BINARY_DIR ${CMAKE_SOURCE_DIR}
            )
endfunction()