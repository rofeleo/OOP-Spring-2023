#include <cstddef>

class ArrayD
{
public:
	ArrayD() = default;
	ArrayD(const ptrdiff_t size); 
	ArrayD(const ArrayD& lhs); // конструктор копирования
	~ArrayD(); // деструктор
	ptrdiff_t ssize() const noexcept; 
	ArrayD& operator=(const ArrayD& lhs);
	double& operator[](const ptrdiff_t index) const;
private:
	ptrdiff_t size = 0;
	double* tail = nullptr;
};
