# this is my first program
a = 2.3
b = 4.5
c = a/b
# plain print
print (a,b,c)

#plain print of more variables
print('c = a/b = ', c)

#old printf style
print('a = %.3f, b = %.3g, c = %2.4g'%(a,b,c))

#print using ""
print("a = {0}, b = {1}, c = {2}".format( a, b, c) )

#print using ''
print('a = {0}, b = {1}, c = {2}'.format( a, b, c) )

# python style formatted output {position:format}
print('a = {0:.3f}, b = {1:.3g}, c = {2:2.4g}'.format( a, b, c) )

# you can also give names to variables to be formatted
print('value = {v:.3f}, error = {err:.3g}, #measurement = {N:3d}'.format( N=1000, v=-1.23454335, err=0.1 ) )
