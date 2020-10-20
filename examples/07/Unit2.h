#ifndef Unit2_h
#define Unit2_h

#include <string>
#include <iostream>

class Unit {
  public:
    Unit(const std::string& name);
    ~Unit();

    std::string name() const { return name_; }
    friend std::ostream& operator<<(std::ostream& os, const Unit& unit);

    int getCount() const { return counter_; }

  private:
    static int counter_;
    std::string name_;
};
#endif
