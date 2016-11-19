#Gustav Solis
#Ranganathan Chidambaranathan
#Recitation 11

def countElements(countList, element1, element2):
    count = 0
    for i in countList:
        if i == element1:
            count += 1
        if i == element2:
            count += 1
    print count

def main():
    userInput = raw_input("Enter a list of elements, separated by a comma: ")
    countList = userInput.split(",")
    element1 = raw_input("Enter the first element to search for: ")
    element2 = raw_input ("Enter the second element to search for: ")
    countElements(countList, element1, element2)


if __name__ == '__main__':
    main()
