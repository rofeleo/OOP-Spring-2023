#pragma once
#ifndef RATIONAL_NUMBERS_HPP_2023
#define RATIONAL_NUMBERS_HPP_2023
#endif 

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Rational {
public:
  Rational() {}
  Rational(const int32_t m, const int32_t n);
  Rational(const int32_t m);
  Rational(const Rational& rhs) = default;
  ~Rational() = default;
  bool operator==(const Rational& rhs) const { return (denum_ == rhs.denum_) && (num_ == rhs.num_); }
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
  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);
private:
  bool ParseToken(const std::string& part, int32_t& num_, int32_t& denum_); // return flag
  static const char devide_ = '/';
  int32_t denum_ = 1;
  int32_t num_ = 0;
  int32_t Gcd(int32_t a, int32_t b) const;
  void DevideByGcd(int32_t& lhs, int32_t& rhs);
};

Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) { return rhs.WriteTo(ostrm); }

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.ReadFrom(istrm); }