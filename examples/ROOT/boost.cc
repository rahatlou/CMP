#include "TLorentzVector.h"
#include "TMath.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {

  // B 4-momentum in the LAB frame
  TLorentzVector p4_B;
  double m_B = 5.279; // GeV
  double p_B = 0.3; // GeV
  p4_B.SetPxPyPzE(p_B, 0, 0, sqrt(p_B*p_B+m_B*m_B));

  // create pion p4 in Center of mass (CoM)
  double m_pi = 0.140; //GeV
  double p_pi = 0.100; // GeV
  TLorentzVector p4_pi;
  p4_pi.SetPxPyPzE(0, p_pi,0, sqrt(m_pi*m_pi+p_pi*p_pi));

  cout << "--> LAB p4 B: " << endl;
  p4_B.Print();

  cout << "--> CoM p4 pi*: " << endl;
  p4_pi.Print();

  cout << "--> boost parameters of B reference frame" << endl;
  cout << "\t beta: " << p4_B.Beta() << "\t"
       << "\t p/E:" << p4_B.P()/p4_B.E() << "\n"
       << "\t gamma: " << p4_B.Gamma() << "\t"
       << "\t E/m: " << p4_B.E()/m_B << "\n"
       << "\t beta*gamma: " << p4_B.Beta()*p4_B.Gamma() << "\t"
       << "\t p/m: " << p_B/m_B
       << endl;


  cout << "--> boost vector of the B meson" << endl;
  p4_B.BoostVector().Print();


  cout << "--> now boost the pion to LAB" << endl;

  p4_pi.Boost( p4_B.BoostVector() );
  cout << "--> LAB p4 pi: " << endl;
  p4_pi.Print();


  return 0;
}
