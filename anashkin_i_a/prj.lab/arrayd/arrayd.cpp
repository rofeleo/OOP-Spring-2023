#include "arrayd/arrayd.hpp"

ArrayD::ArrayD(const ptrdiff_t size)
  : n_objects_(size)
  , capacity_(size * kCapacityRatio_) {
  if (size < 0) {
    throw(std::invalid_argument("size is less than zero"));
  }
  head_ = new double[capacity_];
  std::fill(head_, head_ + n_objects_, kDefaultValue_);
}

ArrayD::ArrayD(const ArrayD& lhs)
  : n_objects_(lhs.n_objects_)
  , capacity_(lhs.capacity_) {
  head_ = new double[capacity_];
  std::copy(lhs.head_, lhs.head_ + lhs.n_objects_, head_);
}

void ArrayD::reserve(const ptrdiff_t& new_size) {
  const ArrayD tmp(*this);
  delete[] head_;
  capacity_ = new_size * kCapacityRatio_;
  head_ = new double[capacity_];
  std::copy(tmp.head_, tmp.head_ + tmp.ssize(), head_);
}

void ArrayD::resize(const ptrdiff_t new_size) {
  if (new_size > capacity_) {
    reserve(new_size);
  }
  if (new_size > n_objects_) {
    std::fill(head_ + n_objects_, head_ + new_size, kDefaultValue_);
  }
  n_objects_ = new_size;
}

ArrayD& ArrayD::operator=(const ArrayD& lhs) {
  if (this != &lhs) {
    this->resize(lhs.ssize());
    std::copy(lhs.head_, lhs.head_ + lhs.ssize(), this->head_);
  }
  return *this;
}

ArrayD::~ArrayD() {
  delete[] head_;
}

ptrdiff_t ArrayD::ssize() const noexcept {
  return n_objects_;
}

const double& ArrayD::operator[](const ptrdiff_t index) const {
  if (0 > index || n_objects_ <= index) {
    throw std::out_of_range("index is out of range");
  }
  return head_[index];
}

double& ArrayD::operator[](const ptrdiff_t index) {
  if (0 > index || n_objects_ <= index) {
    throw std::out_of_range("index is out of range");
  }
  return head_[index];
}

void ArrayD::insert(const ptrdiff_t& position, const double& rhs) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }
  n_objects_ += 1;
  if (capacity_ == n_objects_) {
    reserve(n_objects_);
  }
  head_[n_objects_ - 1] = rhs;
  for (ptrdiff_t i_arr = n_objects_ - 1; i_arr > position; i_arr -= 1) {
    std::swap(head_[i_arr], head_[i_arr - 1]);
  }
}

void ArrayD::remove(const ptrdiff_t& position) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }
  n_objects_ -= 1;
  for (ptrdiff_t i_arr = position; i_arr < n_objects_; i_arr += 1) {
    std::swap(head_[i_arr], head_[i_arr + 1]);
  }
}
