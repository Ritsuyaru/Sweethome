include(FetchContent)

FetchContent_Declare(asio
  GIT_REPOSITORY https://github.com/chriskohlhoff/asio
  GIT_TAG asio-1-34-2
)
FetchContent_GetProperties(asio)
if(NOT asio_POPULATED)
  FetchContent_Populate(asio)
  add_library(asio INTERFACE)
  # see https://think-async.com/Asio/AsioStandalone.html 
  target_compile_definitions(asio INTERFACE ASIO_STANDALONE)
  target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
endif()
