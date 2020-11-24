# Example of `TLorentzVector` in ROOT

This is an example of using the ROOT class
[`TLorentzVector`](https://root.cern.ch/doc/master/classTLorentzVector.html) to
perform kinematic calculations and apply the relativistic boost.

See a previous [lab session](../lab/sessions.md) for the details.

The complete example is in [boost.cc](../examples/ROOT/boost.cc).

First we create the 4-momentum for a B meson in the laboratory frame.
```c++
TLorentzVector p4_B;
double m_B = 5.279; // GeV
double p_B = 0.3; // GeV
p4_B.SetPxPyPzE(p_B, 0, 0, sqrt(p_B*p_B+m_B*m_B));
```
Then we create the 4-momentum for the the pion the B rest frame
```c++
double m_pi = 0.140; //GeV
double p_pi = 0.100; // GeV
TLorentzVector p4_pi;
p4_pi.SetPxPyPzE(0, p_pi,0, sqrt(m_pi*m_pi+p_pi*p_pi));
```
We can print some of the information
```c++
cout << "--> LAB p4 B: " << endl;
p4_B.Print();

cout << "--> CoM p4 pi*: " << endl;
p4_pi.Print();
```

B momemtum:
```
--> LAB p4 B:
(x,y,z,t)=(0.300000,0.000000,0.000000,5.287517) (P,eta,phi,E)=(0.300000,-0.000000,0.000000,5.287517)
```
pion momentum in B rest frame:
```
--> CoM p4 pi*:
(x,y,z,t)=(0.000000,0.100000,0.000000,0.172047) (P,eta,phi,E)=(0.100000,-0.000000,1.570796,0.172047)

```
The class also provide the `Beta()` and `Gamma()` methods to compute the boost parameters, which you can compare with their  definition:
```c++
cout << "--> boost parameters of B reference frame" << endl;
cout << "\t beta: " << p4_B.Beta() << "\t"
     << "\t p/E:" << p4_B.P()/p4_B.E() << "\n"
     << "\t gamma: " << p4_B.Gamma() << "\t"
     << "\t E/m: " << p4_B.E()/m_B << "\n"
     << "\t beta*gamma: " << p4_B.Beta()*p4_B.Gamma() << "\t"
     << "\t p/m: " << p_B/m_B
     << endl;
```

boost parameters of the B frame in Laboratory
```
--> boost parameters of B reference frame
	 beta: 0.0567374		 p/E:0.0567374
	 gamma: 1.00161		 E/m: 1.00161
	 beta*gamma: 0.0568289		 p/m: 0.0568289
```
It also provides the `BoostVector()` method
```c++
cout << "--> boost vector of the B meson" << endl;
p4_B.BoostVector().Print();
```
```
--> boost vector of the B meson
TVector3 A 3D physics vector (x,y,z)=(0.056737,0.000000,0.000000) (rho,theta,phi)=(0.056737,90.000000,0.000000)
```
that we can use to  boost the pion to the LAB frame
```c++
p4_pi.Boost( p4_B.BoostVector() );

cout << "--> LAB p4 pi: " << endl;
p4_pi.Print();
```
**NB**: the boost method modifies the pion 4-momentum:
```
--> LAB p4 pi:
(x,y,z,t)=(0.009777,0.100000,0.000000,0.172324) (P,eta,phi,E)=(0.100477,-0.000000,1.473334,0.172324)
```
the pion `py` is unchanged in the LAB as expected (perpendicular to the boost) and now there is a `px` component due to the boost of the B frame.
