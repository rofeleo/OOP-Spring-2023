#include "rational/rational.hpp"

int32_t Rational::Gcd(const int32_t a, const int32_t b) const {
  return b ? Rational::Gcd(b, a % b) : a;
}


std::istream& Rational::ReadFrom(std::istream& istrm) {
  constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
  int num, denom;
  char slash('/');
  int num_op(0);
  for (;;) {
    istrm >> num >> slash >> denom;
    if (istrm.fail() || slash != devide_ || denom <= 0) {
      istrm.clear();
      if (num_op) {
        istrm.setstate(std::ios_base::goodbit);
      } else {
        istrm.setstate(std::ios_base::failbit);
      }
      return istrm;
    } else {
      *this = Rational(num, denom);
    }
    if (istrm.eof() || static_cast<char>(istrm.peek()) != ' ') return istrm;
    num_op += 1;
  }
  return istrm;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational lhs_copy = lhs;
  lhs_copy /= rhs;
  return lhs_copy;
}

Rational Rational::operator-() const {
  return Rational(-num_, denom_);
}

Rational::Rational(const int32_t m) {
  num_ = m;
  denom_ = 1;
}

Rational::Rational(const int32_t m, const int32_t n) {
  if (n == 0) {
    throw std::invalid_argument("denom_ is equal to zero");
  }
  denom_ = n;
  num_ = m;
  if (n < 0) {
    denom_ *= -1;
    num_ *= -1;
  }
  DevideByGcd(num_, denom_);
}

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = rhs.num_ * denom_ + num_ * rhs.denom_;
  denom_ *= rhs.denom_;
  DevideByGcd(denom_, num_);
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  denom_ *= rhs.denom_;
  num_ *= rhs.num_;
  DevideByGcd(denom_, num_);
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  num_ = num_ * rhs.denom_ - rhs.num_ * denom_;
  denom_ *= rhs.denom_;
  DevideByGcd(denom_, num_);
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (0 == rhs.num_) {
    throw std::invalid_argument("devided by zero!");
  }
  denom_ *= rhs.num_;
  num_ *= rhs.denom_;
  DevideByGcd(denom_, num_);
  return *this;
}

bool Rational::operator>(const Rational& rhs) const {
  int32_t lcm = denom_  * rhs.denom_ / Gcd(denom_, num_);
  return num_ * (lcm / denom_) > rhs.num_ * (lcm / rhs.denom_);
};

bool Rational::operator>=(const Rational& rhs) const {
  return num_ == rhs.num_ || operator>(rhs);
};

bool Rational::operator<(const Rational& rhs) const {
  return !operator>=(rhs);
};

bool Rational::operator<=(const Rational& rhs) const {
  return !operator>(rhs);
};

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << num_ << devide_ << denom_;
  return ostrm;
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