include(FetchContent)

FetchContent_Declare(crow
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
  GIT_TAG v1.2.0
  PATCH_COMMAND git reset --hard HEAD && git init && git apply --verbose --ignore-whitespace "${PROJECT_SOURCE_DIR}/cmake/patches/crow.patch"
)

FetchContent_GetProperties(crow)
if(NOT crow_POPULATED)
  FetchContent_Populate(crow)
  set(CROW_BUILD_EXAMPLES OFF CACHE BOOL "")
  set(CROW_BUILD_TESTS OFF CACHE BOOL "")
  set(CROW_AMALGAMATE OFF CACHE BOOL "")
  set(CROW_INSTALL OFF CACHE BOOL "")
  add_subdirectory(${crow_SOURCE_DIR} ${crow_BINARY_DIR})
  include_directories(${crow_SOURCE_DIR}/include)
endif()
