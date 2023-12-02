# -----------------------------------------------------
#   GENERAL SETTINGS
# -----------------------------------------------------

# We set the minimum version recuired of cmake to build as we have some functionality
# not present in earlier versions of cmake
cmake_minimum_required(VERSION 3.20)

# Creates a file describing the project structure so that the editor can find all the header and c files
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Information about the project
project(
    project
    VERSION 0.1
    DESCRIPTION "Garbage collector for C"
    LANGUAGES C)


# Ensure that atleast std=c14 is used (nessecary for google test)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
# Ensure that std == c++ instead of std == g++
set(CMAKE_C_EXTENSIONS OFF) 

# Here we define all subdirectories that we use to build the project 
# Note: All subdirectories must have their own CMakeLists.txt files defining how 
# to build and execute that module as well as information about that module
add_subdirectory(src/test)
add_subdirectory(apps)
# ....

# OPTIONS: when building the build directory with cmake 
# Whether or not to run with a sanatizer, aka. keep track of allocated and freed
# memory
option(SANATIZE "Run with sanatizer" OFF)
# Option for deter
option(BUILD_TESTING "Build tests for project" ON)

# -----------------------------------------------------
#   PROJECT SPECICFIC SETTINGS
# -----------------------------------------------------

# We only apply these settings if this is the main project
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Tells cmake to generate the test executables that we will ceate in the tests/
    # folder
    enable_testing()

    #TODO: add code coverage for build 
endif()

# If the project chould be built with debugging, we want to eable tracking 
# of memory usage
if (CMAKE_BUILD_TYPE STREQUAL "Debug") 
    option(SANATIZE "Run with sanatizer" ON)
endif()

# Faster alternative to valgrind. Instead of running a separate program around your
# program like valgrind does 
if (SANATIZE EQUAL TRUE) 
    add_compile_options(-fsatitize=address)
    add_link_options(-fsanitize=address)
endif()


# Adding test if the critera are met
# Note: MODERN_CMAKE_BUILD_TESTING is for giving external projects the ability to test 
# the code
if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    # We add the module containing all the defined tests  
    add_subdirectory(tests)
endif()
