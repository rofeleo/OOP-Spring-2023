#pragma once
#ifndef RATIONAL_NUMBERS_HPP_2023
#define RATIONAL_NUMBERS_HPP_2023
#endif 

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <limits>


class Rational {
public:
  Rational() = default;
  explicit Rational(const int32_t m, const int32_t n);
  explicit Rational(const int32_t m);
  Rational(const Rational& rhs) = default;
  ~Rational() = default;
  bool operator==(const Rational& rhs) const { return (denom_ == rhs.denom_) && (num_ == rhs.num_); }
  bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int32_t rhs) { return operator+=(Rational(rhs, 1)); }
  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int32_t rhs) { return operator-=(Rational(rhs, 1)); }
  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int32_t& rhs) { return operator*=(Rational(rhs, 1)); }
  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int32_t rhs) { return operator/=(Rational(rhs, 1)); }
  Rational operator-() const;
  bool operator>(const Rational& rhs) const;
  bool operator>=(const Rational& rhs) const;
  bool operator<(const Rational & rhs) const;
  bool operator<=(const Rational& rhs) const;

public:
  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);

private:
  void DevideByGcd(int32_t& lhs, int32_t& rhs);

private:
  static const char devide_ = '/';
  int32_t denom_ = 1;
  int32_t num_ = 0;
  int32_t Gcd(int32_t a, int32_t b) const;
};

Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) { return rhs.WriteTo(ostrm); }

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.ReadFrom(istrm); }