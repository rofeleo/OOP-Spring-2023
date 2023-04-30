#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>


class MatrixS {
public:
  using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;
  
public:
  MatrixS() = default;
  explicit MatrixS(const SizeType& size = {0, 0});
  ~MatrixS();
  explicit MatrixS(const MatrixS& other);
  MatrixS& operator=(const MatrixS& other);

public:
  int& at(const SizeType& elem);
  const int& at(const SizeType& elem) const;
  int& at(const std::ptrdiff_t i, const std::ptrdiff_t j);
  const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const;
  void resize(const SizeType& new_size);
  void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);
  const SizeType& ssize() const noexcept;
  std::ptrdiff_t nRows() const noexcept;
  std::ptrdiff_t nCols() const noexcept;


private:
  const int kCapacityRatio_ = 2;
  const int kDefaultValue_ = 0;

private:
  std::ptrdiff_t capacity_ = 0;
  std::ptrdiff_t n_rows_ = 0;
  std::ptrdiff_t n_cols_ = 0;
  int* nums_;
  std::vector<int*> p_first_element_;
};
