# Check backward compatibilty
cmake_minimum_required(VERSION 3.11)

# Prevent in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message( FATAL_ERROR  "In-source build is not possible and not recommended. Choose an empty directory for build output.")
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

# Set name project
project(sweethome)

# Version information
set(PROJECT_TEMPLATE_VERSION_MAJOR 0)
set(PROJECT_TEMPLATE_VERSION_MINOR 0)
set(PROJECT_TEMPLATE_VERSION_PATCH 0)

set(PROJECT_TEMPLATE_VERSION
        "${PROJECT_TEMPLATE_VERSION_MAJOR}.${PROJECT_TEMPLATE_VERSION_MINOR}.${PROJECT_TEMPLATE_VERSION_PATCH}")

# Project options
option(sweethome_enable_tests "Build unit tests" ON)

# C++ dialect
set(CMAKE_CXX_STANDARD 20)

# Access to local cmake scripts
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Add Lib
include(add_fmt)
include(add_spdlog)
if (${sweethome_enable_tests})
  include(add_googletest)
endif()
add_subdirectory(third-party/yaml-cpp)

# Add template project sources
add_subdirectory(src)
# add_subdirectory(conf)
if (${sweethome_enable_tests})
  add_subdirectory(tests)
endif()