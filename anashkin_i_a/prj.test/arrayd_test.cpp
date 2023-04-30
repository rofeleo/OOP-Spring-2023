#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "arrayd/arrayd.hpp"

#include <doctest/doctest.h>

#include <algorithm>
#include <iostream>

TEST_CASE("TEST") {
  ArrayD a(5);
  CHECK(a.ssize() == 5);
  a.insert(0, 1);
  CHECK(a.ssize() == 6);
  a.remove(5);
  CHECK(a.ssize() == 5);
  CHECK(a[0] == 1);
  ArrayD b(a);
  CHECK(b.ssize() == a.ssize());
  b.remove(0);
  CHECK(b[0] == 0);
  CHECK(a[0] == 1);
  b.resize(1);
  CHECK(b.ssize() == 1);
  b.insert(0, 1);
}

