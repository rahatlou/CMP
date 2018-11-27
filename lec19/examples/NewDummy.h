#ifndef NewDummy_h_
#define NewDummy_h_

#include<iostream>

template< typename  T >
class NewDummy {
  public:
    NewDummy(const T& data);
    ~NewDummy();
    void print() const;
    static int total() { return total_; }

  private:
    T* data_;
    static int total_;
};

template<class T>
int NewDummy<T>::total_ = 0;


template<class T>
NewDummy<T>::NewDummy(const T& data) {
  data_ = new T(data);
  total_++;
}


template<class T>
NewDummy<T>::~NewDummy() {
  total_--;
  delete data_;
}

template<class T>
void
NewDummy<T>::print() const {
  std::cout << "NewDummy<T>::print() with type T = "
       << typeid(T).name()
       << ", *data_: " << *data_
       << std::endl;
}
#endif
