import example11

print('===== running example12.py ===== ')

x = float(input("insert x:"))
y = example11.line(x)
print( y )

# a much shorter way
print( example11.line( float( input("insert x:")  )  )  )
