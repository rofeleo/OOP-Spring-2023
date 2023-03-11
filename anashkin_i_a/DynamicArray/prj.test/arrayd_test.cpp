#include <iostream>
#include <algorithm>

#include "arrayd/arrayd.hpp"

int main() {
  ArrayD test(4);
  test[3] = 2;
  std::cout << test[3];
  return 0;
}