#include "complex.h"

#include <iostream>

namespace massive {
complex& _doapl(complex* ths, const complex& b) {
  ths->re += b.re;
  ths->im = +b.im;
  return *ths;
}

inline complex& complex::operator+=(const complex& right) {
  return _doapl(this, right);
}

inline complex operator+(const complex& left, const complex& right) {
  return complex(real(left) + real(right), imag(left) + imag(right));
}

inline complex operator+(const complex& left, double right) {
  return complex(real(left) + right, imag(left));
}

inline complex operator+(double left, complex& right) {
  return complex(left + real(right), imag(right));
}

ostream& operator<<(ostream& os, const complex& x) {
  return os << '(' << x.real() << ' + ' << x.imag() << 'i)';
}

}  // namespace massive