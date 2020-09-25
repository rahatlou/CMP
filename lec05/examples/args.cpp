// args.cpp

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

  cout << "# of cmd line arguments argc: " << argc << endl;
  cout << "argv[0]: " << argv[0] << endl;

  if(argc < 4 ) {
    cout << "Error... not enough arguments!" << endl;
    cout << "Usage: args <integer> <double> <string>" << endl;
    cout << "now exiting..." << endl;
    return -1; // can be used by user to determine error condition
  }

  int index = atoi( argv[1] );
  double mean = atof( argv[2] );
  std::string name( argv[3] );

  cout << "Running " << argv[0]
       << " with "
       << "index: " << index
       << ", mean: " << mean
       << ", name: " << name
       << endl;

  return 0;
}
