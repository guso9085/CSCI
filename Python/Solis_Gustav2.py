class Shape:
    def __init__(self):
        self.radius = 0
        self.height = 0
        self.base = 0
        self.length = 0

    def rectangle(self, length, width):
        area = (length * width)
        print area

    def triangle(self, height, base):
        area = (base * height) / 2
        print area

    def circle(self, radius):
        area = (3.14) * (radius * radius)
        print area

def main():
    shape = Shape()
    shape.rectangle(5, 4)
    shape.triangle(10,3)
    shape.circle(10)


main()

''' TEST EXAMPLES
1)
    class Box:
    def __init__(self, length):
        self.length = length

    def getVolume(self):
        return (pow(self.length, 3))

2)

class Student:
    def __init__(self, grade):
        self.grade = grade
        self.scores = []
    def Add(self, value):
        self.scores.extend([value])
    def Highest(self):
        highest = 0
        for i in self.scores:
            if i > highest:
                highest = i

        if len(self.scores) == 0:
            return None
        else:
            return highest

class Student:
    def __init__(self, name):
        self.name = name
        self.scores = []

    def Add(self, value):
        self.scores.extend([value])

    def Mean(self):
        total = 0
        for i in self.scores:
            total = total + i
        if len(self.scores) > 0:
            return total / len(self.scores)
        else:
            return None

3)

class Student:
    def __init__(self, name):
        self.name = name
        self.scores = []

    def Add(self, value):
        self.scores.extend([value])

    def Median(self):
        if len(self.scores) == 0:
            return x
        elif len(self.scores) % 2 == 1:
            return self.scores[int((len(self.scores)/2) + 0.5)]
        elif len(self.scores) % 2 == 0:
            return (self.scores[len(self.scores)/2]+self.scores[((len(self.scores)/2)+1)])/2

class Student:


class Students:
    def __init__(self, names):
        self.scores = {}
        for i in names:
            self.scores[i] = []

    def Add(self, name, value):
        if name in self.scores:
            self.scores[name].append(value)


def myBuild(filename):
    Library = []
    try:
        myFile = open(filename)
        for i in myFile:
            i = i.strip()
            split = i.split("@")
            Library.append([split[0], split[1]])

        return Library
    except:
        return []
