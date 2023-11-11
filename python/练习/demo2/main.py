class dog():
    def __init__(self,a,b):
        self.name=a
        self.age=b
        self.sex="nan"
    def show(self):
        print(self.name)
        print(self.sex)
        print(self.age)
a=dog(3,4)
a.show()
class pet(dog):
    def __init__(self,a,b,c):
        super().__init__(a,b)
        self.tall=c
    def show(self):
        print(self.tall)
adf=pet(3,5,7)
adf.show()
print(adf)






