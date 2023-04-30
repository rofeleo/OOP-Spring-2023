#pragma once
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "matrixs/matrixs.hpp"

#include <doctest/doctest.h>

TEST_CASE("Custom") {
  MatrixS test({ 2, 3 });
  test.resize(4, 5);
  //MatrixS testCopy(test);
  //test.at({0, 0}) = 1;
  //test.at(1, 2) = 54;
  //test.at(0, 0) = 2;
  //CHECK(test.at(1, 1) == 0);
  /*for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << test.at(i, j) << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << testCopy.at(i, j) << " ";
    }
    std::cout << "\n";
  }*/

}