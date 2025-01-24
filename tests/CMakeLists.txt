enable_testing()

add_subdirectory(conf)

add_executable(
    test_readYaml
    test_readYaml.cpp
    ../src/settings.h ../src/settings.cpp
)
target_link_libraries(test_readYaml
    PUBLIC
    GTest::gtest_main
    PRIVATE
    yaml-cpp
    spdlog
)

include(GoogleTest)
gtest_discover_tests(test_readYaml)