find_package(googletest QUIET)

if (NOT googletest_FOUND)
  include(FetchContent)

  FetchContent_Declare(googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG v1.14.0
  )

  FetchContent_GetProperties(googletest)
  if(NOT googletest_POPULATED)
    message(STATUS "Downloading, Configuring and Generating 'GoogleTest' dependency")
    FetchContent_Populate(googletest)

    # TODO: handle the visual studio case when using static runtime
    # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  else()
    message(STATUS "GoogleTest already populated")
  endif()
endif()

if (TARGET gtest)
  message(STATUS "GoogleTest")
else()
  message(STATUS "GoogleTest NOT FOUND")
endif()
