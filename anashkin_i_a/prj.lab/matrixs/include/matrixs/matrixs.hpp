#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>


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
  void resize(std::ptrdiff_t new_n_rows, std::ptrdiff_t new_n_cols);
  const SizeType& ssize() const noexcept;
  std::ptrdiff_t nRows() const noexcept;
  std::ptrdiff_t nCols() const noexcept;

private:
  const int kDefaultValue_ = 0;
  const int kCapacityRowRatio_ = 1;
  const int kCapacityColRatio_ = 1;
  std::ptrdiff_t capacity_row_ = 0;
  std::ptrdiff_t capacity_col_ = 0;
  std::ptrdiff_t n_rows_ = 0;
  std::ptrdiff_t n_cols_ = 0;
  int* nums_;
  std::vector<int*> p_first_element_;
};
