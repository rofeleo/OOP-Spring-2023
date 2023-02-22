#include <iostream>
#include "lib/Rational.hpp"

bool TestParse(const std::string& str) {
  std::istringstream istrm(str);
  Rational q;
  istrm >> q;
  }