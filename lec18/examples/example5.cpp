// example5.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template< typename  T >
class Dummy {
  public:
    Dummy(const T& data);
    ~Dummy();
    void print() const;

  private:
    T* data_;
};

template<class T>
Dummy<T>::Dummy(const T& data) {
  data_ = new T(data);
}


template<class T>
Dummy<T>::~Dummy() {
  delete data_;
}

template<class T>
void
Dummy<T>::print() const {
  cout << "Dummy<T>::print() with type T = "
       << typeid(T).name()
       << ", *data_: " << *data_
       << endl;

}


int main() {
  Dummy<std::string> d1( std::string("test") );

  double x = 1.23;
  Dummy<double> d2( x );

  d1.print();
  d2.print();

  return 0;
}
