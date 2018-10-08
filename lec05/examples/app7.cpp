// app7.cpp
#include <iostream>
using namespace std;

int main() {


    double* ptr1 = new double[100000];
    ptr1[0] = 1.1;

    cout << "ptr1[0]: " << ptr1[0]
         << endl;


    int* ptr2 = new int[1000];
    ptr2[233] = -13423;

    cout << "&ptr1: "<< &ptr1 << "  sizeof(ptr1): " << sizeof(ptr1)
         << "  ptr1: " << ptr1 << endl;
        
    cout << "&ptr2: "<< &ptr2 << "  sizeof(ptr2): " << sizeof(ptr2)
         << " ptr2: " << ptr2 << endl;

    delete[] ptr1;
    delete[] ptr2;

    return 0;
}
