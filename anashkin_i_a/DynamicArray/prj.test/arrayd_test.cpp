#include <iostream>
#include <algorithm>

#include "arrayd/arrayd.hpp"

int main() {
  ptrdiff_t size = 5;
  ArrayD A(size);
  for (int i = 0; i < size; ++i) {
    A[i] = i + 6 % 3;
  }
  std::cout << A << "\n";
  ArrayD B = A;
  std::cout << B << "\n";
  B.Resize(2);
  std::cout << B;

  return 0;
}