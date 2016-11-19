#Gustav Solis
#Ranganathan Chidambaranathan
#Assignment 10
#Problems 1,2,3

def CreateDictionary(File):
    Library = {}
    myFile = open(File)
    for line in myFile:
        line = line.strip()
        split = line.split(",")
        Library[split[0]] = split[1]

    return Library

def Deslang(slang, Library):
    deslanged = ""
    split = slang.split(" ")
    for i in range(len(split)):
        if split[i] in Library:
            split[i] = Library[split[i]]
    for i in range(len(split)):
        deslanged = deslanged + str(split[i]) + " "
    return deslanged


def main():
    File = "textToEnglish.txt"
    Abbreviation = ""
    Abbreviations = ""
    Library = CreateDictionary(File)
    while (Abbreviation != "quit"):
        Abbreviation = raw_input("Enter a text abbreviation: ")
        if Abbreviation in Library:
            print Library[Abbreviation]
        else:
            print "Not Found"

    while (Abbreviations != "quit"):
        Abbreviations = raw_input("Enter a number of abbreviations: ")
        deslanged = Deslang(Abbreviations, Library)
        print deslanged


if __name__ == '__main__':
    main()
