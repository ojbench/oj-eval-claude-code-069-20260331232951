cmake_minimum_required(VERSION 3.10)
project(memory_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

# If no cpp files found, create a dummy target
if(NOT SOURCES)
    message(WARNING "No .cpp files found. Creating dummy target.")
    add_custom_target(code ALL
        COMMAND ${CMAKE_COMMAND} -E echo "No source files to compile"
        COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/code
    )
else()
    add_executable(code ${SOURCES})
    target_include_directories(code PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endif()
