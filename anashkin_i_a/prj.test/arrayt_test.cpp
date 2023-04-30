#pragma once
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "arrayt/arrayt.hpp"

#include <iostream>
#include <doctest/doctest.h>


TEST_CASE("Arrayt test") {
  ArrayT<int> a(5);

  REQUIRE(a.ssize() == 5);

}




