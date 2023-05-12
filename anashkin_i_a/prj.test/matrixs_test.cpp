#pragma once
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "matrixs/matrixs.hpp"

#include <doctest/doctest.h>

TEST_CASE("All") {
  MatrixS a({ 3, 4 });
  a.resize({ 1, 1 });
  CHECK_THROWS(a.at(0, 1));
  CHECK_THROWS(a.at(1, 1));
  CHECK_THROWS(a.at(1, 0));
  a.at({ 0, 0 }) = 3;
  CHECK(a.at(0, 0) == 3);
  MatrixS b(a);
  CHECK(b.at(0, 0) == 3);
  a.at({ 0, 0 }) = 6;
  CHECK(b.at(0, 0) == 3);
  CHECK(a.at(0, 0) == 6);
  a.resize(3, 4);
  a.at(2, 3) = 7;
  a.resize(5, 6);
  CHECK(a.at(2, 3) == 7);
}