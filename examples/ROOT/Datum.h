#ifndef Datum_h
#define Datum_h
// Datum.h
#include <iostream>

class Datum {
  public:
    Datum();
    Datum(double x, double y);
    Datum(const Datum& datum);
    ~Datum() { };

    double value() const { return value_; }
    double error() const { return error_; }
    double significance() const;
    void print() const;

    void setValue(double v) { value_ = v; }
    void setError(double e) { error_ = e; }

    Datum operator+( const Datum& rhs ) const;
    const Datum& operator+=( const Datum& rhs );

    Datum sum( const Datum& rhs ) const;

    const Datum& operator=( const Datum& rhs );


    bool operator==(const Datum& rhs) const;
    bool operator<(const Datum& rhs) const;

    Datum operator*( const Datum& rhs ) const;
    Datum operator/( const Datum& rhs ) const;

    Datum operator*( const double& rhs ) const;

    

    friend Datum operator*(const double& lhs, const Datum& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Datum& rhs);

    static void setTolerance(double val) { tolerance_ = val; };
    
  private:
    double value_;
    double error_;
    static double tolerance_;
};
#endif
