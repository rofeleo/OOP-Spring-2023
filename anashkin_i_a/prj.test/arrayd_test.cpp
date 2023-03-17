#include <iostream>
#include <algorithm>

#include "arrayd/arrayd.hpp"

int main() {
  ArrayD A(2);
  std::cout << A << "\n";
  A.Resize(5);
  std::cout << A[4] << "\n";
  std::cout << A;
  ArrayD B = A;
  std::cout << B << "\n";
  B[3] = 2;
  std::cout << B << "\n";

  return 0;
}