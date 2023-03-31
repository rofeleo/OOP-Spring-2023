#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

template<class T>
class ArrayT {
public:
	ArrayT() = default;
	ArrayT(const ptrdiff_t size); 
	ArrayT(const ArrayT& lhs);
	ArrayT& operator=(const ArrayT& lhs);
	~ArrayT();
	ptrdiff_t Ssize() const noexcept; 
	T& operator[](const ptrdiff_t index);
	const T& operator[](const ptrdiff_t index) const; 
	void Resize(const ptrdiff_t new_size);
	std::ostream& write_to(std::ostream& ostrm) const noexcept;
	void Insert(const ptrdiff_t& position, const T& rhs);
	void Remove(const ptrdiff_t& position);
private:
	const ptrdiff_t capacity_ratio_ = 2;
	void Reserve(const ptrdiff_t& capacity);
	ptrdiff_t capacity_ = 2;
	const T default_value_ = 0;
	ptrdiff_t n_objects_ = 0;
	T* head_ = nullptr;
};

template<class T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs) noexcept;