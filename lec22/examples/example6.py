import mymodule

print("++++ executing " +  __file__ + " with name space " + __name__)

print( mymodule.line( 2.34, q=0.5 )  )

print( "mymodule.a: %f"%mymodule.a )
