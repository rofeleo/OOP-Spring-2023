#include "matrixs/matrixs.hpp"

MatrixS::MatrixS(const SizeType& size) :
  n_rows_(get<0>(size)),
  capacity_row_(get<0>(size) * kCapacityRowRatio_),
  n_cols_(get<1>(size)),
  capacity_col_(get<1>(size) * kCapacityColRatio_)
{
  nums_ = new int[capacity_col_ * capacity_row_];
  p_first_element_.resize(capacity_row_);
  for (int i_row(0); i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nums_ + i_row * capacity_col_;
    std::fill(p_first_element_[i_row], p_first_element_[i_row] + capacity_col_, kDefaultValue_);
  }
}

MatrixS::~MatrixS() {
  delete[] nums_;
  for (int i_row(0); i_row < n_rows_; i_row += 1) {
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
    if (capacity_col_ * capacity_row_ < other.n_cols_ * other.n_rows_) {
      delete[] nums_;
      nums_ = new int[n_rows_ * n_cols_];
      std::copy(other.nums_, other.nums_ + other.n_rows_ * other.n_cols_, nums_);
      p_first_element_.resize(n_rows_ * n_cols_);
      for (int i_row = 0; i_row < n_rows_; i_row += 1) {
        p_first_element_[i_row] = nums_ + n_cols_ * i_row;
      }
    } else {
      for (int i_num = other.n_cols_ * other.n_rows_; i_num < n_rows_ * n_cols_; i_num += 1) {
        delete (nums_ + i_num);
      }
      for (int i_row = other.n_rows_; i_row < n_rows_; i_row += 1) {
        p_first_element_[i_row] = nullptr;
      }
      n_rows_ = other.n_rows_;
      n_cols_ = other.n_cols_;
    }
    
    p_first_element_.resize(n_rows_);
    nums_ = new int[n_cols_ * n_rows_];
    std::copy(other.nums_, other.nums_ + other.n_rows_ * other.n_cols_, nums_);
    
    
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

void MatrixS::resize(std::ptrdiff_t new_n_rows, std::ptrdiff_t new_n_cols) {
  if (new_n_rows < n_rows_) {
    n_rows_ = new_n_rows;
  } else if (new_n_rows > n_rows_) {
    if (new_n_rows >= capacity_row_) {
      MatrixS copy(*this);
      capacity_row_ = new_n_rows * kCapacityRowRatio_;
      delete[] nums_;
      nums_ = new int[capacity_col_ * capacity_row_];
      p_first_element_.resize(capacity_row_);
      std::copy(copy.nums_, copy.nums_ + copy.capacity_col_ * copy.capacity_row_, nums_);
      for (int i_row(copy.n_rows_); i_row < new_n_cols; i_row += 1) {
        p_first_element_[i_row] = nums_ + i_row * capacity_col_;
        std::fill(p_first_element_[i_row], p_first_element_[i_row] + capacity_col_, kDefaultValue_);
      }
    }
    for (int i(0); i < capacity_col_ * capacity_row_; i += 1) {
      std::cout << nums_[i] << " ";
    }
    std::cout << "\n";
  }
  if (new_n_cols < n_cols_) {
    n_cols_ = new_n_cols;
  } else if (new_n_cols > n_rows_) {

  }
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


