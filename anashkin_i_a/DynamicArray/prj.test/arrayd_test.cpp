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
  B.resize(2);
  std::cout << B;
  try {
    std::cout << B[-1];
  }
  catch (const std::out_of_range& ex) {
    std::cerr << ex.what();
    return 1;
  }

  return 0;
}