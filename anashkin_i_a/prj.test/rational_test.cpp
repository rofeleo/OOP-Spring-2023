#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "rational/rational.hpp"

#include <iostream>
#include <doctest/doctest.h>

TEST_CASE("Unary minus") {
  CHECK(-Rational(3, 1) == Rational(-3, 1));
  SUBCASE("with reduce") {
    CHECK(-Rational(4, 6) == Rational(2, -3));
  }
}

TEST_CASE("Input") {
  Rational r;
  std::stringstream sstrm;
  SUBCASE("Simple") {
    sstrm.str("3/2");
    sstrm >> r;
    CHECK(r == Rational(3, 2));
    CHECK(sstrm.eof());
    sstrm.clear();
  }
  SUBCASE("with witespaces") {
    sstrm.str("  3/2");
    sstrm >> r;
    CHECK(r == Rational(3, 2));
    CHECK(sstrm.eof());
    sstrm.clear();
  }
  SUBCASE("with witespaces at the end") {
    sstrm.str("3/2  ");
    sstrm >> r;
    CHECK(r == Rational(3, 2));
    CHECK(sstrm.good());
    sstrm.clear();
  }
  SUBCASE("with witespaces at the end and at the beggining") {
    sstrm.str("  3/2  ");
    sstrm >> r;
    CHECK(r == Rational(3, 2));
    CHECK(sstrm.good());
    sstrm.clear();
  }
  SUBCASE("three rational") {
    sstrm.str("3/2 4/2 6/3");
    sstrm >> r;
    CHECK(r == Rational(6, 3));
    CHECK(sstrm.eof());
    sstrm.clear();
  }
}
//
//TEST_CASE("Comparison") {
//  SUBCASE("Greater") {
//    CHECK(Rational(1, 2) > Rational(1, 4));
//  }
//  SUBCASE("Greater or equal") {
//    CHECK(Rational(1, 2) >= Rational(2, 4));
//    CHECK(Rational(1, 2) >= Rational(1, 4));
//    CHECK_FALSE(Rational(4, 8) >= Rational(3, 1));
//  }
//  SUBCASE("Less or equal") {
//    CHECK(Rational(1, 2) <= Rational(2, 4));
//  }
//  SUBCASE("Less") {
//    CHECK(Rational(1, 2) < Rational(5, 2));
//  }
//}
