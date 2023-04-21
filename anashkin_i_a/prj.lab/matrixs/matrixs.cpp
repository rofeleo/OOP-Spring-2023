#include "matrixs/matrixs.hpp"

MatrixS::MatrixS(const SizeType& size) {
  nums_.resize(get<0>(size) * get<1>(size));
  p_first_elements_.resize(get<0>(size));
}

MatrixS::~MatrixS() {
  for (auto i_pointer = p_first_elements_.begin(); i_pointer != p_first_elements_.end(); i_pointer += 1) {
    delete *i_pointer;
    *i_pointer = nullptr;
  }
}

MatrixS::MatrixS(const MatrixS& other) {
  nums_ = other.nums_;
  for (auto i_pointer = other.p_first_elements_.begin(); i_pointer != other.p_first_elements_.end(); i_pointer += 1) {
    p_first_elements_.push_back(new int(**i_pointer));
  }
}
