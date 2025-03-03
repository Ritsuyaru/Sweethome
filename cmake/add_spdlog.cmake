include(FetchContent)

FetchContent_Declare(spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.15.0
)

FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
  FetchContent_Populate(spdlog)
  set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "" FORCE)
  add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
  # add_library(spdlog::spdlog ALIAS spdlog)
endif()

set_target_properties(spdlog PROPERTIES FOLDER deps)