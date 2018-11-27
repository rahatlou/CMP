#include <iostream>

template<class T, int maxSize=7>
class Vector {
  public:
    Vector() {
      size_ = maxSize;
      for(int i=0; i<size_; ++i) {
        data_[i] = T();
      }
    }

    ~Vector() {};
    int size() const { return size_; }
    T& operator[](int index);
    const T& operator[](int index) const;
    //friend std::ostream& operator<<(ostream& os, const Vector<T,maxSize>& vec);

  private:
    int size_;
    T data_[maxSize];
};

template<typename T, int maxSize>
T& Vector<T,maxSize>::operator[](int index){
  return data_[index];
}

template<typename T, int maxSize>
const T& Vector<T,maxSize>::operator[](int index) const{
  return data_[index];
}

template<typename T, int maxSize>
std::ostream& 
operator<<(std::ostream& os, const Vector<T,maxSize>& vec) {
  os << "vector with " << vec.size() << " elements: " << endl;
  for(int i=0; i<vec.size(); ++i) {
    os << "i: " << i
       << " v[i]: " << vec[i] << endl;
  }
  return os;
}
