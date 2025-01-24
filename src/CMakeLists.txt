set(SRC_FILES
    settings.h settings.cpp
)

add_executable(sweethome
    main.cpp
    ${SRC_FILES}
)

target_link_libraries(sweethome
    PRIVATE
    yaml-cpp
    spdlog
)

target_include_directories(sweethome PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)