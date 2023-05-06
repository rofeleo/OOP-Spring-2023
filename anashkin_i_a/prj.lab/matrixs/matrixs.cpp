#include "matrixs/matrixs.hpp"

MatrixS::MatrixS(const SizeType& size) :
  n_rows_(get<0>(size)),
  capacity_row_(get<0>(size) * kCapacityRowRatio_),
  n_cols_(get<1>(size)),
  capacity_col_(get<1>(size) * kCapacityColRatio_)
{
  nums_ = new int[capacity_col_ * capacity_row_];
  std::fill(nums_, nums_ + capacity_col_ * capacity_row_, kDefaultValue_);
  p_first_element_.resize(capacity_row_);
  for (int i_row(0); i_row < capacity_row_; i_row += 1) {
    p_first_element_[i_row] = nums_ + i_row * capacity_col_;
  }
}

MatrixS::~MatrixS() {
  delete[] nums_;
  for (int i_row(0); i_row < capacity_row_; i_row += 1) {
    p_first_element_[i_row] = nullptr;
  }
}

MatrixS::MatrixS(const MatrixS& other) :
  capacity_row_(other.capacity_row_),
  capacity_col_(other.capacity_col_),
  n_rows_(other.n_rows_),
  n_cols_(other.n_cols_)
{
  nums_ = new int[capacity_col_ * capacity_row_];
  std::copy(other.nums_, other.nums_ + other.capacity_col_ * other.capacity_row_, nums_);
  p_first_element_.resize(capacity_row_);
  for (int i_row(0); i_row < capacity_row_; i_row += 1) {
    p_first_element_[i_row] = nums_ + i_row * capacity_col_;
  }
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
  if (this != &other) {
    this->resize(other.n_rows_, other.n_cols_);
    for (int i_row(0); i_row < other.n_rows_; i_row += 1) {
      p_first_element_[i_row] = nums_ + i_row * capacity_col_;
      std::copy(other.nums_ + i_row * other.capacity_col_, other.nums_ + i_row * other.capacity_col_ + other.n_cols_, p_first_element_[i_row]);
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
  resize(get<0>(new_size), get<1>(new_size));
}

void MatrixS::resize(std::ptrdiff_t new_n_rows, std::ptrdiff_t new_n_cols) {
  if (new_n_rows >= capacity_row_ || new_n_cols >= capacity_col_) {
    MatrixS copy(*this);
    delete[] nums_;
    if (new_n_rows >= capacity_row_) {
      capacity_row_ = new_n_rows * kCapacityRowRatio_;
      p_first_element_.resize(capacity_row_);
    }
    if (new_n_cols >= capacity_col_) {
      capacity_col_ = new_n_cols * kCapacityColRatio_;
    }
    nums_ = new int[capacity_col_ * capacity_row_];
    std::fill(nums_, nums_ + capacity_col_ * capacity_row_, kDefaultValue_);
    for (int i_row(0); i_row < capacity_row_; i_row += 1) {
      p_first_element_[i_row] = nums_ + i_row * capacity_col_;
      if (i_row < copy.n_rows_) {
        std::copy(copy.nums_ + i_row * copy.capacity_col_, copy.nums_ + i_row * copy.capacity_col_ + copy.n_cols_, p_first_element_[i_row]);
      }
    }
  } 
  
  n_cols_ = new_n_cols;
  n_rows_ = new_n_rows;
}

const MatrixS::SizeType& MatrixS::ssize() const noexcept {
  return MatrixS::SizeType(n_rows_, n_cols_);
}

std::ptrdiff_t MatrixS::nRows() const noexcept
{
  return n_rows_;
}

std::ptrdiff_t MatrixS::nCols() const noexcept
{
  return n_cols_;
}


