#ifndef Vector3D_h
#define Vector3D_h
#include <iostream>

class Vector3D {
  public:
    Vector3D(const double& x=0, const double& y=0, const double& z=0) ;


    const Vector3D& operator=(const Vector3D& rhs);
    const Vector3D& operator+=(const Vector3D& rhs);

    const Vector3D operator+(const Vector3D& rhs) const;
    const Vector3D operator-(const Vector3D& rhs) const;

    const Vector3D& operator=(const double& a); // set all components  = a

    const Vector3D operator/(const double a) const ; // vector / scalar

    const Vector3D operator*(const double a) const; // scalar x double

    friend const Vector3D operator*(const double a, const Vector3D& rhs); // scalar x vector

    friend  std::ostream& operator<<(std::ostream& os, const Vector3D& rhs);

    double mod() const;
    double distance(const Vector3D& r0) const;

  private:
    double x_[3];

};
#endif
