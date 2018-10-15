#ifndef Unit_h
#define Unit_h

#include <string>
#include <iostream>

class Unit {
  public:
    Unit(const std::string& name);
    ~Unit();

    std::string name() const { return name_; }
    friend std::ostream& operator<<(std::ostream& os, const Unit& unit);

    static int counter_;

  private:
    std::string name_;
};
#endif
