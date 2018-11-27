#ifndef DummyBis_h_
#define DummyBis_h_

template< typename  T >
class DummyBis {
  public:
    DummyBis(const T& data);
    ~DummyBis();
    void print() const;

  private:
    T* data_;
};
#endif
