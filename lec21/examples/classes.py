class Datum:
    def __init__(self,val,err):
        self.val = val
        self.err = err
    def __add__(self, other):
        import math as m
        return Datum(self.val+other.val, m.sqrt(self.err**2+other.err**2) )
    def __str__(self):
        return "%f +/- %f"%(self.val, self.err)

class Person:
    def __init__(self,n=None):
        self.name = n

    def __str__(self):
        return "[Class Person] name: %s"%self.name

    def display(self):
        print(self.name)



if __name__ == "__main__":
 x = Datum(1.1, 0.2)
 y = Datum(-0.5, 0.2)
 z = x + y
 print(z)

 john = Person()
 print(john)

 susan = Person("Susy")
 print(susan)
