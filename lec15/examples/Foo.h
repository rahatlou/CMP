template< typename  T >
class Foo {
  public:
    Foo(const T& data);
    ~Foo();
    void print() const;
    // friend of all specializations
    friend void nicePrint();

    // friend of specialization with same type
    friend void specialPrint( const Foo<T>& obj);

    // member function of Bar friend of all specilizations
    friend void Bar::printFoo();

    // member function of Dummy with same type
    friend void Dummy<T>::print(const Foo<T> & f )

  private:
    T* data_;
};
