#pragma once
#ifndef RATIONAL_NUMBERS_HPP_2023
#define RATIONAL_NUMBERS_HPP_2023
#endif 

#include <iostream>
#include <sstream>
#include <stdexcept>

class Rational {
public:
  Rational() {}
  Rational(const int32_t m, const int32_t n);
  Rational(const int32_t m);
  Rational(const Rational& rhs) = default;
  ~Rational() = default;
  bool operator==(const Rational& rhs) const { return (devider_ == rhs.devider_) && (devisible_ == rhs.devisible_); }
  bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int32_t rhs) { return operator+=(Rational(rhs, 1)); }
  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int32_t rhs) { return operator-=(Rational(rhs, 1)); }
  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int32_t& rhs) { return operator*=(Rational(rhs, 1)); }
  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int32_t rhs) { return operator/=(Rational(rhs, 1)); }
  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);
private:
  static const char devide_ = '/';
  int32_t devider_ = 1;
  int32_t devisible_ = 0;
  int32_t Gcd(int32_t a, int32_t b) const;
  void DevideByGcd(int32_t& lhs, int32_t& rhs);
};

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) { return rhs.WriteTo(ostrm); }

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.ReadFrom(istrm); }