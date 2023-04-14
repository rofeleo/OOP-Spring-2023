#include "rational/rational.hpp"

int32_t Rational::Gcd(const int32_t a, const int32_t b) const {
  return b ? Rational::Gcd(b, a % b) : a;
}

bool Rational::ParseToken(const std::string& expr, int32_t& num_, int32_t& denum_) {
  std::string::const_iterator separator_pos = expr.end();
  
  for (auto i_symb = expr.begin(); i_symb != expr.end(); i_symb += 1) {
    if (*i_symb == '/') {
      if (separator_pos != expr.end() || i_symb == expr.begin() || i_symb == expr.end() - 1) return 0;
      else separator_pos = i_symb;
    } else if (!(*i_symb >= '0' && *i_symb <= '9' || *i_symb == '-')) return 0;
  }
  num_ = std::stoi(expr.substr(0, separator_pos - expr.begin()));
  denum_ = std::stoi(expr.substr(separator_pos - expr.begin() + 1, expr.end() - separator_pos));
  return 1;
}


std::istream& Rational::ReadFrom(std::istream& istrm) {
  int num(0), denum(1);
  char slash(0);
  istrm >> num;
  istrm.get(slash);
  int trash = istrm.peek();
  istrm >> denum;
  if (!istrm || trash > '9' || trash < '0') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  if (istrm.good() || istrm.eof()) {
    if (Rational::devide_ == slash && denum > 0) {
      *this = Rational(num, denum);
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational lhs_copy = lhs;
  lhs_copy /= rhs;
  return lhs_copy;
}

Rational Rational::operator-() const {
  return Rational(-num_, denum_);
}

Rational::Rational(const int32_t m) {
  num_ = m;
  denum_ = 1;
}

Rational::Rational(const int32_t m, const int32_t n) {
  if (n == 0) {
    throw std::invalid_argument("denum_ is equal to zero");
  }
  denum_ = n;
  num_ = m;
  if (n < 0) {
    denum_ *= -1;
    num_ *= -1;
  }
  DevideByGcd(num_, denum_);
}

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = rhs.num_ * denum_ + num_ * rhs.denum_;
  denum_ *= rhs.denum_;
  DevideByGcd(denum_, num_);
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  denum_ *= rhs.denum_;
  num_ *= rhs.num_;
  DevideByGcd(denum_, num_);
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  num_ = num_ * rhs.denum_ - rhs.num_ * denum_;
  denum_ *= rhs.denum_;
  DevideByGcd(denum_, num_);
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (0 == rhs.num_) {
    throw std::invalid_argument("devided by zero!");
  }
  denum_ *= rhs.num_;
  num_ *= rhs.denum_;
  DevideByGcd(denum_, num_);
  return *this;
}

bool Rational::operator>(const Rational& rhs) const {
  int32_t lcm = denum_  * rhs.denum_ / Gcd(denum_, num_);
  return num_ * (lcm / denum_) > rhs.num_ * (lcm / rhs.denum_);
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
  ostrm << num_ << devide_ << denum_;
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