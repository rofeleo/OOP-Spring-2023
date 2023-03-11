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

ArrayD::~ArrayD() {
  delete[] head_;
}

ptrdiff_t ArrayD::ssize() const noexcept
{
  return size_;
}

const double& ArrayD::operator[](const ptrdiff_t index) const {
  return head_[index];
}

double& ArrayD::operator[](const ptrdiff_t index) {
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
