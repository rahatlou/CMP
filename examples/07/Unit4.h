#ifndef Unit4_h
#define Unit4_h
#include <string>
#include <iostream>

class Unit {
  public:
    Unit(const std::string& name);
    ~Unit();

    std::string name() const { return name_; }
    friend std::ostream& operator<<(std::ostream& os, const Unit& unit);

    static int getCount() {
      name_ = "";
      return counter_;
    }

  private:
    static int counter_;
    std::string name_;
};
#endif
