// const2.cpp

int main() {

   int a = 1;
   int * const b = &a; // const pointer to int

   *b = 5; // OK. can change value of what b points to

   int c = 3;
   b = &c; // Not OK. assign new value to c

   return 0;
}
