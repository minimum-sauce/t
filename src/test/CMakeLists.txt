# Tell cmake where to find the header list for this module
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${sprint_2_SOURCE_DIR}/include/test/*.h")

# We create a lirary of this module making it available to be used as a dependency
# for other parts of the program
add_library(
    hello
    hello.c
    )

# we now include the .h files in the library so that they are accessable from the 
# outside
# great explanation of PRIVATE, PUBLIC and INTERFACE for cmake:
# https://cmake.org/pipermail/cmake/2016-May/063400.html
target_include_directories(
    hello
    PUBLIC ${project_SOURCE_DIR}/include
    )
target_compile_features(hello PUBLIC c_std_17)

# target link_libraries(
#     hello
#     PRIVATE <dependencies>
# )


# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules) 
# include(CodeCoverage)
# append_coverage_compiler_flags()
# 
# source_group(
#     TREE "${PROJECT_SOURCE_DIR}/include"
#     PREFIX "Header Files"
#     FILES "${HEADER_LIST}"
# )
