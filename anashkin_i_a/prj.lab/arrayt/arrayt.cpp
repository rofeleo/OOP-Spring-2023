#include "arrayt/arrayt.hpp"

template<class T>
ArrayT<T>::ArrayT(const ptrdiff_t size)
  : n_objects_(size)
  , capacity_(size * capacity_ratio_) {
  if (size < 0) {
    throw(std::invalid_argument("size is less than zero"));
  }
  head_ = new T[capacity_];
  std::fill(head_, head_ + n_objects_, default_value_);
}

template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& lhs)
  : n_objects_(lhs.n_objects_)
  , capacity_(lhs.capacity_) {
  head_ = new T[capacity_];
  std::copy(lhs.head_, lhs.head_ + lhs.n_objects_, head_);
}

template<class T>
void ArrayT<T>::Reserve(const ptrdiff_t& new_size) {
  const ArrayT tmp = *this;
  delete[] head_;
  capacity_ = new_size * capacity_ratio_;
  head_ = new T[capacity_];
  std::copy(tmp.head_, tmp.head_ + tmp.Ssize(), head_);
}

template<class T>
void ArrayT<T>::Resize(const ptrdiff_t new_size) {
  if (new_size > capacity_) {
    Reserve(new_size);
  }
  if (new_size > n_objects_) {
    std::fill(head_ + n_objects_, head_ + new_size, default_value_);
  }
  n_objects_ = new_size;
}

template<class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& lhs) {
  if (this != &lhs) {
    this->Resize(lhs.Ssize());
    std::copy(lhs.head_, lhs.head_ + lhs.Ssize(), this->head_);
  }
  return *this;
}

template<class T>
ArrayT<T>::~ArrayT() {
  delete[] head_;
}

template<class T>
ptrdiff_t ArrayT<T>::Ssize() const noexcept {
  return n_objects_;
}

template<class T>
const T& ArrayT<T>::operator[](const ptrdiff_t index) const {
  if (0 > index || n_objects_ <= index) {
    throw std::out_of_range("index is out of range");
  }
  return head_[index];
}

template<class T>
T& ArrayT<T>::operator[](const ptrdiff_t index) {
  if (0 > index || n_objects_ <= index) {
    throw std::out_of_range("index is out of range");
  }
  return head_[index];
}

template<class T>
std::ostream& ArrayT<T>::write_to(std::ostream& ostrm) const noexcept {
  ostrm << "size: " << Ssize() << "\n";
  for (ptrdiff_t i = 0; i < Ssize(); i += 1) {
    ostrm << head_[i] << " ";
  }
  return ostrm;
}

template<class T>
void ArrayT<T>::Insert(const ptrdiff_t& position, const T& rhs) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }
  n_objects_ += 1;
  if (capacity_ == n_objects_) {
    Reserve(n_objects_);
  }
  head_[n_objects_ - 1] = rhs;
  for (ptrdiff_t i_arr = n_objects_ - 1; i_arr > position; i_arr -= 1) {
    std::swap(head_[i_arr], head_[i_arr - 1]);
  }
}

template<class T>
void ArrayT<T>::Remove(const ptrdiff_t& position) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }
  n_objects_ -= 1;
  for (ptrdiff_t i_arr = position; i_arr < n_objects_; i_arr += 1) {
    std::swap(head_[i_arr], head_[i_arr + 1]);
  }
}

template<class T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs) noexcept {
  return rhs.write_to(ostrm);
}
