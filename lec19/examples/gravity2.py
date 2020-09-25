import matplotlib.pyplot as plt
import math
import numpy as np

g = 9.8

h = 0.
while True:
    x = input("initial height h in m: (press return for h = 0 m): ")
    if x == "":  break
    h = float(x)
    if(h>=0): break


theta = 20.
while True:
    x = input("angle theta in [0,90] degrees (press return for {0} degree): ".format(theta))
    if x == "" : break
    theta  = float(x)
    if(theta>0 and theta<90): break
theta = (theta/90.)*math.pi/2.


v0 = 10.
while True:
    x = input("insert v_0 > 0 in m/s (press return for {0} m/s): ".format(v0))
    if x == "":  break
    v0 = float(x)
    if(v0>0): break

dt=0.1
while True:
    x = input("insert dt > 0 in sec (press return for {0} sec): ".format(dt))
    if x == "": break
    dt = float(x)
    if(dt>0): break


v0x = v0*math.cos(theta)
v0y = v0*math.sin(theta)

print("v0_x: %.3f m/s \t v0_y: %.3f m/s"%(v0x,v0y))

x0 = 0
y0 = h

def x(t):
    return x0+v0x*t

def y(t):
    return y0+v0y*t-0.5*g*t*t


# generate list of times for sampling
times = np.arange(0., 1000., 0.01).tolist()

#print first 10 elements
print(times[:10])

# compute x(t_i)
xi = [ x(t) for t in times if y(t)>=0.]

# compute y(t_i)
yi = [ y(t) for t in times if y(t)>=0. ]

print( "total steps:\t %-4d"%len(xi))
print( "last x:\t\t %.2f"%xi[-1])
print( "last y:\t\t %.3f"%yi[-1])

#print(x,y)
plt.plot(xi,yi)

# we also make the plot nicer
plt.title('motion under gravity')
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.grid(True)
plt.xlim(-0.1, max(xi)*1.1)
plt.ylim(-0.1,max(yi)*1.10)

plt.savefig('/tmp/gravity2.pdf')
