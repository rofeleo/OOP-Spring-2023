#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

class ArrayD
{
public:
	ArrayD() = default;
	ArrayD(const ptrdiff_t size); 
	ArrayD(const ArrayD& lhs);
	ArrayD& operator=(const ArrayD& lhs);
	~ArrayD();
	ptrdiff_t Ssize() const noexcept; 
	double& operator[](const ptrdiff_t index);
	const double& operator[](const ptrdiff_t index) const; 
	void Resize(const ptrdiff_t new_size);
	std::ostream& write_to(std::ostream& ostrm) const noexcept;
	void Insert(const ptrdiff_t& position, const double& rhs);
private:
	const ptrdiff_t capacity_ratio_ = 2;
	void Reserve(const ptrdiff_t& capacity);
	ptrdiff_t capacity_ = 2;
	const double default_value_ = 0;
	ptrdiff_t n_objects_ = 0;
	double* head_ = nullptr;
};


std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept;