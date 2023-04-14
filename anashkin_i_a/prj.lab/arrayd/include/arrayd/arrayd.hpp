#pragma once
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
	void Resize(const ptrdiff_t new_size);
	void Insert(const ptrdiff_t& position, const double& rhs);
	void Remove(const ptrdiff_t& position);
	std::ostream& WriteTo(std::ostream& ostrm) const noexcept; // not in conversation
	ptrdiff_t Ssize() const noexcept;

private:
	void Reserve(const ptrdiff_t& capacity);

private:
	const ptrdiff_t kCapacityRatio_ = 2;
	ptrdiff_t capacity_ = 2;
	const double kDefaultValue_ = 0;
	ptrdiff_t n_objects_ = 0;
	double* head_ = nullptr;
};

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept;