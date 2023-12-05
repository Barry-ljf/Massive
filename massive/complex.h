#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
namespace massive {
class complex {
 public:
  complex(double r = 0, double i = 0) : re(r), im(i) {}
  complex& operator+=(const complex& right);
  double real() const { return re; }
  double imag() const { return im; }  // implicity point this

 private:
  double re, im;

  friend complex& _doapl(complex* ths, const complex& b);
};
inline complex operator+(const complex& left, const complex& right);
inline complex operator+(const complex& left, double right);
inline complex operator+(double left, complex& right);
}  // namespace massive
#endif