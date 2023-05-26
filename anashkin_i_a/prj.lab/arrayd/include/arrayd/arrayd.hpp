#ifndef ARRAYD_HPP_31_03_2023
#define ARRAYD_HPP_31_03_2023
#endif 

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

class ArrayD {
public:
	ArrayD() = default;
	explicit ArrayD(const ptrdiff_t size); 
	explicit ArrayD(const ArrayD& lhs);
	ArrayD& operator=(const ArrayD& lhs);
	~ArrayD();
	double& operator[](const ptrdiff_t index);
	const double& operator[](const ptrdiff_t index) const;
	
public:
	void resize(const ptrdiff_t new_size);
	void insert(const ptrdiff_t& position, const double& rhs);
	void remove(const ptrdiff_t& position);
	ptrdiff_t ssize() const noexcept;

private:
	void reserve(const ptrdiff_t& capacity);

private:
	const ptrdiff_t kCapacityRatio_ = 2;
	ptrdiff_t capacity_ = 2;
	const double kDefaultValue_ = 0;
	ptrdiff_t n_objects_ = 0;
	double* head_ = nullptr;
};