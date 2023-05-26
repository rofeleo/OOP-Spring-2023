#ifndef ARRAYT_HPP_31_03_2023
#define ARRAYT_HPP_31_03_2023
#endif 

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

template<class T>
class ArrayT {

public:
	ArrayT() = default;
	~ArrayT();
	explicit ArrayT(const ptrdiff_t size); 
	explicit ArrayT(const ArrayT& lhs);
	ArrayT& operator=(const ArrayT& lhs);
	T& operator[](const ptrdiff_t index);
	const T& operator[](const ptrdiff_t index) const; 

public:
	ptrdiff_t ssize() const noexcept; 
	void resize(const ptrdiff_t new_size);
	void insert(const ptrdiff_t& position, const T& rhs);
	void remove(const ptrdiff_t& position);

private:
	void Reserve(const ptrdiff_t& capacity);

private:
	const ptrdiff_t capacity_ratio_ = 2;
	ptrdiff_t capacity_ = 2;
	const T kDefaultValue_ = T();
	ptrdiff_t n_objects_ = 0;
	T* head_ = nullptr;
};

template<class T>
ArrayT<T>::ArrayT(const ptrdiff_t size)
  : n_objects_(size)
  , capacity_(size* capacity_ratio_) {
  if (size < 0) {
    throw(std::invalid_argument("size is less than zero"));
  }
  head_ = new T[capacity_];
  std::fill(head_, head_ + n_objects_, kDefaultValue_);
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
  const ArrayT tmp(*this);
  delete[] head_;
  capacity_ = new_size * capacity_ratio_;
  head_ = new T[capacity_];
  std::copy(tmp.head_, tmp.head_ + tmp.ssize(), head_);
}

template<class T>
void ArrayT<T>::resize(const ptrdiff_t new_size) {
  if (new_size > capacity_) {
    Reserve(new_size);
  }
  if (new_size > n_objects_) {
    std::fill(head_ + n_objects_, head_ + new_size, kDefaultValue_);
  }
  n_objects_ = new_size;
}

template<class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& lhs) {
  if (this != &lhs) {
    this->resize(lhs.ssize());
    std::copy(lhs.head_, lhs.head_ + lhs.ssize(), this->head_);
  }
  return *this;
}

template<class T>
ArrayT<T>::~ArrayT() {
  delete[] head_;
}

template<class T>
ptrdiff_t ArrayT<T>::ssize() const noexcept {
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
void ArrayT<T>::insert(const ptrdiff_t& position, const T& rhs) {
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
void ArrayT<T>::remove(const ptrdiff_t& position) {
  if (0 > position || n_objects_ <= position) {
    throw(std::out_of_range("index is out of range"));
  }
  n_objects_ -= 1;
  for (ptrdiff_t i_arr = position; i_arr < n_objects_; i_arr += 1) {
    std::swap(head_[i_arr], head_[i_arr + 1]);
  }
}
