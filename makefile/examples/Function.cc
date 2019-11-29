#include "Function.h"
#include <iostream>

Function::Function(const std::string& name) {
  name_ = name;
}

void
Function::print() const {
  std::cout << "Function with name " << name_ << std::endl;
}
