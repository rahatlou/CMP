import matplotlib.pyplot as plt
import math

g = 9.8

h = 10.
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
theta = math.radians(theta)


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

t=0.
x=[]
y=[]
xi=0
yi=h

while yi>=0:
    x.append(xi)
    y.append(yi)
    t+=dt
    xi=v0x*t
    yi=h+v0y*t-0.5*g*t*t

#print(x,y)
plt.plot(x,y)

# we also make the plot nicer
plt.title('motion under gravity')
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.grid(True)
plt.xlim(-0.1, max(x)*1.1)
plt.ylim(-0.1,max(y)*1.10)

plt.savefig('/tmp/gravity2.pdf')
