# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(LOG_SYS)


# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    log.cpp
    test.cpp
)

# Add an executable with the above sources
add_executable(LOG_SYS
    ${SOURCES}
)


# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(LOG_SYS
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/inc
)
