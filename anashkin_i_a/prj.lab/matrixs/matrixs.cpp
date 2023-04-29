#include "matrixs/matrixs.hpp"

MatrixS::MatrixS(const SizeType& size): 
  n_rows_(get<0>(size)), 
  n_cols_(get<1>(size)) 
{
  nums_.resize(n_rows_ * n_cols_);
  p_first_elements_.resize(n_rows_);
}

MatrixS::~MatrixS() {
  for (auto i_pointer = p_first_elements_.begin(); i_pointer != p_first_elements_.end(); i_pointer += 1) {
    delete *i_pointer;
    *i_pointer = nullptr;
  }
}

MatrixS::MatrixS(const MatrixS& other) {
  nums_ = other.nums_;
  n_rows_ = other.n_rows_;
  n_cols_ = other.n_cols_;
  for (auto i_pointer = other.p_first_elements_.begin(); i_pointer != other.p_first_elements_.end(); i_pointer += 1) {
    p_first_elements_.push_back(new int(**i_pointer));
  }
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
  if (this != &other) {
     
  }
  return *this;
}

int& MatrixS::at(const SizeType& elem) {
  return nums_[0];
}

const int& MatrixS::at(const SizeType& elem) const {
  return nums_[0];
}

int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
  return nums_[0];
}

const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
  return nums_[0];
}

void MatrixS::resize(const SizeType& new_size)
{

}

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j)
{
}

const MatrixS::SizeType& MatrixS::ssize() const noexcept {
  return MatrixS::SizeType{ 2, 3 };
}

std::ptrdiff_t MatrixS::nRows() const noexcept
{
  return std::ptrdiff_t();
}

std::ptrdiff_t MatrixS::nCols() const noexcept
{
  return std::ptrdiff_t();
}


