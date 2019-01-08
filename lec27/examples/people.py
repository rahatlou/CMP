class Person:
    def __init__(self,name=None):
        self.name = name

    def __str__(self):
        return "[Class Person] name: %s"%self.name

    def display(self):
        print(self.name)


class Student(Person):
    def __init__(self, name, id):
        Person.__init__(self,name)
        self.id = id
    def __str__(self):
        return "[Class Student] name: %s id: %i"%(self.name, self.id)

    def display(self):
        print("Student: %s  id: %i"%(self.name, self.id) )



class Professor(Person):
    def __init__(self, name, age, courses):
        Person.__init__(self,name)
        self.age = age
        self.courses = courses
    def __str__(self):
        return "[Class Professor] name: %s age: %i #courses: %d"%(self.name, self.age, len(self.courses) )


    def display(self):
        print("Name: %s  age: %i course: %s"%(self.name, self.age, self.courses) )



if __name__ == "__main__":
    john = Person("johnny")
    joe = Person()
    anna = Student("Anna", id=12345456)
    andrea = Professor("Andrea", age=41, courses=['lab1', 'optics', 'computing'])

    people = [ john, joe, anna, andrea]

    for p in people:
        print(p)
