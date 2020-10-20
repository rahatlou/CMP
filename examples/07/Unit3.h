#ifndef Unit3_h
#define Unit3_h

#include <string>
#include <iostream>

class Unit {
  public:
    Unit(const std::string& name);
    ~Unit();

    std::string name() const { return name_; }
    friend std::ostream& operator<<(std::ostream& os, const Unit& unit);

    static int getCount() { return counter_; }

  private:
    static int counter_;
    std::string name_;
};
#endif
