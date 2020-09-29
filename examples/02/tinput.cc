//tinput.cc
#include <iostream>
using namespace std;

int main() {

  cout << "iterations? ";

  int iters = 0;
  cin >> iters;

  if(cin.fail()) cout << "cin failed!" << endl;

  cout << "requested " << iters << " iterations" << endl;

  return 0;
}
