add_executable(sweethome
    main
)

target_link_libraries(sweethome
    PRIVATE
)

target_include_directories(sweethome PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)