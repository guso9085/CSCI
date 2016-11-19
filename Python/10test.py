import Assignment10_Solis


def main():
    File = "textToEnglish.txt"
    Abbreviation = ""
    Abbreviations = ""
    Library = Assignment10_Solis.CreateDictionary(File)
    while (Abbreviation != "quit"):
        Abbreviation = raw_input("Enter a text abbreviation: ")
        if Abbreviation in Library:
            print Library[Abbreviation]
        else:
            print "Not Found"

    while (Abbreviations != "quit"):
        Abbreviations = raw_input("Enter a number of abbreviations: ")
        deslanged = Assignment10_Solis.Deslang(Abbreviations, Library)
        print deslanged


if __name__ == "__main__":
    main()
