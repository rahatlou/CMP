import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import time
import math as m


# initial conditions
g = 9.8
h = 10.
theta = m.radians(30.)
v0 = 30.
dt=0.01

#compute velocity components
v0x = v0*np.cos(theta)
v0y = v0*np.sin(theta)
print("v0_x: %.3f m/s \t v0_y: %.3f m/s"%(v0x,v0y))

x0 = 0
y0 = h

def x(t):
    return x0+v0x*t

def y(t):
    return y0+v0y*t-0.5*g*t*t


dt = 0.01
# generate list of times for sampling
times = np.arange(0., 1000., dt)

# compute x(t_i)
xi = [ x(t) for t in times if y(t)>=0.]

# compute y(t_i)
yi = [ y(t) for t in times if y(t)>=0. ]

print("max height: %.2f at x = %.2f"%(max(yi),xi[yi.index(max(yi))]))


# create a figure object
fig = plt.figure()

# add subplot (just 1) and set x and y limits based on data
# ax is the object containing objects to be plotted
ax = fig.add_subplot(111, autoscale_on=False, xlim=(-0.1, max(xi)*1.2), ylim=(-0.1,max(yi)*1.2) )
ax.grid()
ax.set_xlabel('x(t) [m]')
ax.set_ylabel("y(t) [m]")
plt.title("trajectory of a projectile with $v_0$: %.1f m/s\t $\Theta_0$: %.1f$^\circ$"%(v0,theta))



# plot initial plot
# ax.plot() returns a list of Linne2D objects. we need just the fist one
line,*_ = ax.plot(xi[0], yi[0], '--', lw=1)
ball,*_ = ax.plot([], [], 'o-', lw=2, color='red')

# define a template info box to be shown
info_template = 'time = %.1fs  x: %.2fm   y: %.3fm'
info_text = ax.text(0.05, 0.95, '', transform=ax.transAxes)


def animate(i):

    line.set_data(xi[:i], yi[:i])
    ball.set_data(xi[i], yi[i])
    info_text.set_text(info_template % (times[i], xi[i],yi[i]))
    return line, ball, info_text

#ani = animation.FuncAnimation(fig, animate, np.arange(1, len(xi)), interval=1, blit=True, repeat_delay=1000)
ani = animation.FuncAnimation(fig, animate, np.arange(1, len(xi)), interval=1, blit=True, repeat=False)


plt.title("trajectory of a projectile with $v_0$: %.1f m/s\t $\Theta_0$: %.1f$^\circ$"%(v0,theta))
plt.show()
