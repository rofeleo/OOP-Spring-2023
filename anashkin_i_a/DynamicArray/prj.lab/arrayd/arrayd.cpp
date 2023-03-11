#include "arrayd/arrayd.hpp"

ArrayD::ArrayD(const ptrdiff_t size) {
  head_ = new double[size];
  size_ = size;
  std::fill(head_, head_ + size_, default_value_);
}

ArrayD::ArrayD(const ArrayD& lhs) {
  size_ = lhs.size_;
  head_ = new double[size_];
  for (ptrdiff_t offset = 0; offset < size_; offset += 1) {
    head_[offset] = lhs.head_[offset];
  }
}

ArrayD& ArrayD::operator=(const ArrayD& lhs) {
  this->resize(lhs.ssize());
  for (ptrdiff_t offset = 0; offset < lhs.ssize(); offset += 1) {
    head_[offset] = lhs[offset];
  }
  return *this;
}

ArrayD::~ArrayD() {
  delete[] head_;
}

ptrdiff_t ArrayD::ssize() const noexcept
{
  return size_;
}

void ArrayD::resize(const ptrdiff_t new_size) {
  const ArrayD tmp = *this;
  delete[] head_;
  size_ = new_size;
  head_ = new double[new_size];
  std::fill(head_, head_ + new_size, default_value_);
  for (ptrdiff_t offset = 0; offset < std::min(new_size, tmp.ssize()); offset += 1) {
    head_[offset] = tmp[offset];
  }
}

const double& ArrayD::operator[](const ptrdiff_t index) const {
  if (0 > index || index >= size_) {
    throw std::out_of_range("index is out of range");
  }
  return head_[index];
}

double& ArrayD::operator[](const ptrdiff_t index) {
  if (0 > index || index >= size_) {
    throw std::out_of_range("index is out of range");
  }
  return head_[index];
}

std::ostream& ArrayD::write_to(std::ostream& ostrm) const noexcept {
  ostrm << "size: " << ssize() << "\n";
  for (ptrdiff_t i = 0; i < ssize(); i += 1) {
    ostrm << head_[i] << " ";
  }
  return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept {
  return rhs.write_to(ostrm);
}
