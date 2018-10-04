// tinput_bad2.cc
#include <iostream>
using namespace std;

int main() {


  int iters;
  cout << "iters before cin: " << iters << endl; 

  cout << "iterations? ";
  cin >> iters;

  cout << "requested " << iters << " iterations" << endl;

  return 0;
}
