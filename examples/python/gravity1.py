import matplotlib.pyplot as plt
import math

# initial conditions
g = 9.8
h = 0.
theta = math.radians(45.)
v0 = 10.
dt=0.01

#compute velocity components
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
plt.savefig("/tmp/gravity1.png")
