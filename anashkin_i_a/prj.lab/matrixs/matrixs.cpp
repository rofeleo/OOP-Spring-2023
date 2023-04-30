#include "matrixs/matrixs.hpp"

MatrixS::MatrixS(const SizeType& size): 
  n_rows_(get<0>(size)), 
  n_cols_(get<1>(size)) 
{
  nums_ = new int[n_rows_ * n_cols_];
  p_first_element_.resize(n_rows_);
  for (int i_num = 0; i_num < n_rows_ * n_cols_; i_num += 1) {
    nums_[i_num] = kDefaultValue_;
    if (i_num % n_cols_ == 0) {
      p_first_element_[i_num / n_cols_] = nums_ + i_num;
    }
  }
}

MatrixS::~MatrixS() {
  delete[] nums_;
  for (int i_row = 0; i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nullptr;
  }
}

MatrixS::MatrixS(const MatrixS& other):
  n_rows_(other.n_rows_),
  n_cols_(other.n_cols_)
{
  p_first_element_.resize(n_rows_);
  nums_ = new int[n_cols_ * n_rows_];
  std::copy(other.nums_, other.nums_ + other.n_rows_ * other.n_cols_, nums_);
  for (int i_row = 0; i_row < n_rows_; i_row += 1) {
      p_first_element_[i_row] = nums_ + n_cols_ * i_row;
  }
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
  if (this != &other) {
    n_rows_ = other.n_rows_;
    n_cols_ = other.n_cols_;
    p_first_element_.resize(n_rows_);
    nums_ = new int[n_cols_ * n_rows_];
    std::copy(other.nums_, other.nums_ + other.n_rows_ * other.n_cols_, nums_);
    for (int i_row = 0; i_row < n_rows_; i_row += 1) {
      p_first_element_[i_row] = nums_ + n_cols_ * i_row;
    }
  }
  return *this;
}

int& MatrixS::at(const SizeType& elem) {
  return at(get<0>(elem), get<1>(elem));
}

const int& MatrixS::at(const SizeType& elem) const {
  return at(get<0>(elem), get<1>(elem));
}

int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
  return *(p_first_element_[i] + j);
}

const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
  return *(p_first_element_[i] + j);
}

void MatrixS::resize(const SizeType& new_size) {
  
  
}

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
  /*MatrixS copy(*this);
  n_rows_ = i;
  n_cols_ = j;
  delete[] nums_;
  for (int i_row = 0; i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nullptr;
  }
  nums_ = new int[n_cols_ * n_rows_];
  
  std::cout << n_cols_;*/
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


