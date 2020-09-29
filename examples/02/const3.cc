// const3.cpp

int main() {

   int a = 1;
   const int * b = &a; // pointer to const int

   int c = 3;
   b = &c; // assign new value to c ... OK!

   *b = 5; // assign new value to what c point to ... NOT OK!

   return 0;
}
