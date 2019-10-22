// enum1.cc
#include <iostream>
using namespace std;

int main() {
  enum FitStatus  { Succesful, Failed, Problems, Converged };

  FitStatus status;

  status = Succesful;
  cout << "Status: " << status << endl;

  status = Converged;
  cout << "Status: " << status << endl;

  return 0;
}
