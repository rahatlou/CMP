
class Person:
  def setName(self,n):
    self.name = n
  def display(self):
    print(self.name)

if __name__ == "__main__":
    john = Person()
    john.setName("John")
    john.display()
    print(john)
