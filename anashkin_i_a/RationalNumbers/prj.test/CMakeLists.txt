add_executable(test_lib "test.cpp")
target_link_libraries(test_lib rational doctest::doctest)
add_test(NAME test_lib COMMAND test_lib)
