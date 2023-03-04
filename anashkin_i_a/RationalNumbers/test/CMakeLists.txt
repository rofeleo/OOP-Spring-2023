add_executable(test_lib "test.cpp" "test.hpp")
target_link_libraries(test_lib Rational doctest::doctest)
add_test(NAME rational_test COMMAND rational_test)
