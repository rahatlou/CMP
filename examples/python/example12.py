import example1

x = float(input("insert x:"))
y = example1.line(x)
print( y )

# a much shorter way
print( example1.line( float( input("insert x:")  )  )  )
