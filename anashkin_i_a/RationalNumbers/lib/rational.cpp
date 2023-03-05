#include "rational.hpp"

int32_t Rational::Gcd(const int32_t a, const int32_t b) const {
  return b ? Rational::Gcd(b, a % b) : a;
}

Rational::Rational(const int32_t m) {
  *this = Rational(m, 1);
}

Rational::Rational(const int32_t m, const int32_t n) {
  if (n == 0) {
    throw std::invalid_argument("denum is equal to zero");
  }
  devider_ = n;
  devisible_ = m;
  if (n < 0) {
    devider_ *= -1;
    devisible_ *= -1;
  }
  DevideByGcd(devisible_, devider_);
}

Rational& Rational::operator+=(const Rational& rhs) {
  devisible_ = rhs.devisible_ * devider_ + devisible_ * rhs.devider_;
  devider_ *= rhs.devider_;
  DevideByGcd(devider_, devisible_);
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  devider_ *= rhs.devider_;
  devisible_ *= rhs.devisible_;
  DevideByGcd(devider_, devisible_);
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  devisible_ = rhs.devisible_ * devider_ - devisible_ * rhs.devider_;
  devider_ *= rhs.devider_;
  DevideByGcd(devider_, devisible_);
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (0 == rhs.devisible_) {
    throw std::invalid_argument("devided by zero!");
  }
  devider_ *= rhs.devisible_;
  devisible_ *= rhs.devider_;
  DevideByGcd(devider_, devisible_);
  return *this;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << devisible_ << devide_ << devider_;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
  int32_t m, n;
  char devide_;
  istrm >> m >> devide_ >> n;
  if (istrm.good()) {
    if (Rational::devide_ == devide_) {
      DevideByGcd(m, n);
      devisible_ = m;
      devider_ = n;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

void Rational::DevideByGcd(int32_t& lhs, int32_t& rhs) { 
  int32_t gcd = Gcd(std::abs(lhs), std::abs(rhs));
  lhs /= gcd;
  rhs /= gcd;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum -= rhs;
  return sum;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum += rhs;
  return sum;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational mul = lhs;
  mul *= rhs;
  return mul;
}