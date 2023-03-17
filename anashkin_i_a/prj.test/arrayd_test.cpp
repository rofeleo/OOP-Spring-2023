#include <iostream>
#include <algorithm>

#include "arrayd/arrayd.hpp"

int main() {
  ArrayD A(2);
  std::cout << A << "\n";
  A.Insert(1, 2);
  std::cout << A << "\n";
  A.Insert(1, 3);
  std::cout << A << "\n";
  A.Remove(1);
  std::cout << A << "\n";
  return 0;
}