#include <cstddef>
// #include <iosfwd>
#include <iostream>
#include <algorithm>
#include <string>

class ArrayD
{
public:
	ArrayD() = default;
	ArrayD(const ptrdiff_t size); 
	ArrayD(const ArrayD& lhs); // конструктор копирования
	ArrayD& operator=(const ArrayD& lhs);
	~ArrayD(); // деструктор
	ptrdiff_t ssize() const noexcept; 
	double& operator[](const ptrdiff_t index); // нужно добавить исключения
	const double& operator[](const ptrdiff_t index) const; // нужно добавить исключения
	void resize(const ptrdiff_t new_size);

	std::ostream& write_to(std::ostream& ostrm) const noexcept;

private:
	const double default_value_ = 0;
	ptrdiff_t size_ = 0;
	double* head_ = nullptr;
};


std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept;