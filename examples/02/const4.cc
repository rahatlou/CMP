// const4.cpp

int main() {

   float a = 1;
   const float * const b = &a; // const pointer to const float

   *b = 5; // Not OK. can't change value of what b points to

   float c = 3;
   b = &c; // Not OK. can't change what b points to!

   return 0;
}
