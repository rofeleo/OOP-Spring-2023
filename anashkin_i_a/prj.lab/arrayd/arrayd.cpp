#include "arrayd/arrayd.hpp"

ArrayD::ArrayD(const ptrdiff_t size)
  : n_objects_(size)
  , capacity_(size * capacity_ratio_) {
  if (size < 0) {
    throw(std::invalid_argument("size is less than zero"));
  }
  head_ = new double[capacity_];
  std::fill(head_, head_ + n_objects_, default_value_);
}

ArrayD::ArrayD(const ArrayD& lhs)
  : n_objects_(lhs.n_objects_)
  , capacity_(lhs.capacity_) {
  head_ = new double[capacity_];
  std::copy(lhs.head_, lhs.head_ + lhs.n_objects_, head_);
}

void ArrayD::Reserve(const ptrdiff_t& new_size) {
  const ArrayD tmp = *this;
  delete[] head_;
  capacity_ = new_size * capacity_ratio_;
  head_ = new double[capacity_];
  std::copy(tmp.head_, tmp.head_ + tmp.Ssize(), head_);
}

void ArrayD::Resize(const ptrdiff_t new_size) {
  if (new_size > capacity_) {
    Reserve(new_size);
  }
  if (new_size > n_objects_) {
    std::fill(head_ + n_objects_, head_ + new_size, default_value_);
  }
  n_objects_ = new_size;
}

ArrayD& ArrayD::operator=(const ArrayD& lhs) {
  if (this != &lhs) {
    this->Resize(lhs.Ssize());
    std::copy(lhs.head_, lhs.head_ + lhs.Ssize(), this->head_);
  }
  return *this;
}

ArrayD::~ArrayD() {
  delete[] head_;
}

ptrdiff_t ArrayD::Ssize() const noexcept {
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

std::ostream& ArrayD::write_to(std::ostream& ostrm) const noexcept {
  ostrm << "size: " << Ssize() << "\n";
  for (ptrdiff_t i = 0; i < Ssize(); i += 1) {
    ostrm << head_[i] << " ";
  }
  return ostrm;
}

void ArrayD::Insert(const ptrdiff_t& position, const double& rhs) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }
  n_objects_ += 1;
  if (position == n_objects_) {
    head_[n_objects_ - 1] = rhs;
  }
  
}

void ArrayD::Remove(const ptrdiff_t& position) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }

}

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept {
  return rhs.write_to(ostrm);
}
