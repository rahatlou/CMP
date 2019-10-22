// enum3.cc
#include <iostream>
using namespace std;

int main() {
  enum Color  { Red=1, Blue=45, Yellow=17, Black=342 };

 Color col;

  col = Red;
  cout << "Color: " << col << endl;

  col = Black;
  cout << "Color: " << col << endl;

  col = 45; //assign int to enum

  int i = Red;

  return 0;
}
