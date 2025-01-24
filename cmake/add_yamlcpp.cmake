# find_package(yaml-cpp QUIET)

# if (NOT yaml-cpp_FOUND)
#   include(FetchContent)
# # message("add yaml lib")
#   FetchContent_Declare(yaml-cpp
#     GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
#     GIT_TAG yaml-cpp-0.7.0
#   )

#   FetchContent_GetProperties(yaml-cpp)
#   if(NOT yaml-cpp_POPULATED)
#     message(STATUS "Downloading, Configuring and Generating 'yaml-cpp' dependency")
#     FetchContent_Populate(yaml-cpp)

#     # TODO: handle the visual studio case when using static runtime
#     # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#     add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
#   else()
#     message(STATUS "yaml-cpp already populated")
#   endif()
# endif()

# if (TARGET gtest)
#   message(STATUS "yaml-cpp")
# else()
#   message(STATUS "yaml-cpp NOT FOUND")
# endif()






include(FetchContent)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG yaml-cpp-0.7.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)

target_link_libraries(yaml-cpp PUBLIC yaml-cpp::yaml-cpp) # The library or executable that require yaml-cpp library