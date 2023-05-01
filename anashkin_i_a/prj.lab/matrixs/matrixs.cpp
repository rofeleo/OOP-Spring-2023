#include "matrixs/matrixs.hpp"

MatrixS::MatrixS(const SizeType& size) :
  n_rows_(get<0>(size)),
  n_cols_(get<1>(size)),
  capacity_(get<1>(size) * get<0>(size) * kCapacityRatio_)
{
  nums_ = new int[capacity_];
  p_first_element_.resize(n_rows_ * kCapacityRowRatio_);
  for (int i_row(0); i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nums_ + i_row * n_cols_ * kCapacityColRatio_;
    std::fill(p_first_element_[i_row], p_first_element_[i_row] + n_cols_, kDefaultValue_);
  }
}

MatrixS::~MatrixS() {
  delete[] nums_;
  for (int i_row(0); i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nullptr;
  }
}

MatrixS::MatrixS(const MatrixS& other) :
  n_rows_(other.n_rows_),
  n_cols_(other.n_cols_),
  capacity_(other.n_rows_ * other.n_cols_ * kCapacityRatio_)
{
  p_first_element_.resize(n_rows_ * kCapacityRowRatio_);
  nums_ = new int[capacity_];
  for (int i_row(0); i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nums_ + i_row * n_cols_ * kCapacityColRatio_;
    std::copy(other.p_first_element_[i_row], other.p_first_element_[i_row] + other.n_cols_, p_first_element_[i_row]);
  }
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
  if (this != &other) {
    if (capacity_ < other.n_cols_ * other.n_rows_) {
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

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
  if (capacity_ < i * j) {
    MatrixS copy(*this);
    delete[] nums_;
    capacity_ = i * j * kCapacityRatio_;
    nums_ = new int[capacity_];
    std::copy(copy.nums_, copy.nums_ + copy.n_cols_ * copy.n_rows_, nums_);
    p_first_element_.resize(capacity_);
  } 
  //std::fill(nums_ + , nums_ + copy.n_cols_ * copy.n_cols_, nums_);
  for (int i_row(0); i_row < n_rows_; i_row += 1) {
    p_first_element_[i_row] = nums_ + n_cols_ * i_row;
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


