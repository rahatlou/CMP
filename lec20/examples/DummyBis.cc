#include "DummyBis.h"
#include<iostream>
using namespace std;

template<class T>
DummyBis<T>::DummyBis(const T& data) {
  data_ = new T(data);
}


template<class T>
DummyBis<T>::~DummyBis() {
  delete data_;
}

template<class T>
void
DummyBis<T>::print() const {
  cout << "DummyBis<T>::print() with type T = "
       << typeid(T).name()
       << ", *data_: " << *data_
       << endl;

}
