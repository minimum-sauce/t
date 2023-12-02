## For automatically adding google test to the project
#include(FetchContent)
#
## We fetch the wanted release of googletest 
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
#

# This creates a new executable that can be built by cmake
add_executable(
    hello_test
    hello_test.c
    )

target_compile_features(hello_test PRIVATE c_std_17)
# We link the executable to the external CUnit library
target_link_libraries(
    hello_test
    PRIVATE hello cunit
    )
# We add the executable to be seen as a test
add_test(NAME "Hello Test" COMMAND ./hello_test)

