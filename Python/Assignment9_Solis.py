#Gustav Solis
#Ranganathan Chidambaranathan
#Assignment 9
#Problems 1,2,3,4

#Calculates the new pop
def CalcNewPopulation(CPop):
    NPop = 0.0
    Year = 31536000.0
    Birth = 1.0/7
    Death = 1.0/13
    Immigrant = 1.0/35
    NPop = CPop + (Birth * Year) + (Immigrant * Year) - (Death * Year)
    return NPop

#Breaks down a number of seconds
def BreakoutTime(Time):
    Days = 0
    Hours = 0
    Minutes = 0
    Seconds = 0
    while (Time > 0):
        if (Time >= 86400):
            Days = Days + 1
            Time = Time - 86400
        else:
            if (Time >= 3600):
                Hours = Hours + 1
                Time = Time - 3600
            else:
                if (Time >= 60):
                    Minutes = Minutes + 1
                    Time = Time - 60
                else:
                    Seconds = Time
                    Time = 0
    NTime = [Days, Hours, Minutes, Seconds]
    return NTime

#Finds a given codon in a string and lists its position
def ListCodonPositions(Sequence, Codon):
    for i in range(len(Sequence)):
        if (Sequence[i] == Codon[0] and Sequence[i+1] == Codon[1] and Sequence[i+2] == Codon[2]):
            print str(i + 1),

#Picks a story given a choice, and returns the string
def MadLib(Story):
    Story1 = "Be kind to your <noun>-footed <plural noun>, or a duck may be somebody's <noun>"
    Story2 = "It was the <adjective1> of <noun1>, it was the <adjective2> of <noun2>."
    Story3 = "<plural noun>? I don't have to show you any <adjective> <plural noun>!"
    Story4 = "My <relative> always said <noun> was like a box of <noun>. You never know what you're gonna get."
    Story5 = "One <time of day>, I <verb> a <noun> in my pajamas. How he got in my pajamas, I don't know."
    if Story == 1:
        Noun = raw_input("Enter noun: ")
        Plural = raw_input ("Enter plural noun: ")
        NStory = "Be kind to your %s-footed %s, or a duck may be somebody's %s." % (Noun, Plural, Noun)
        return NStory

    if Story == 2:
        Adj1 = raw_input("Enter adjective1: ")
        Noun1 = raw_input ("Enter noun1: ")
        Adj2 = raw_input("Enter adjective2: ")
        Noun2 = raw_input ("Enter noun2: ")
        NStory = "It was the %s of %s, it was the %s of %s." % (Adj1, Noun1, Adj2, Noun2)
        return NStory

    if Story == 3:
        Plural = raw_input("Enter plural noun: ")
        Adj = raw_input ("Enter adjective: ")
        NStory = "%s? I don't have to show you any %s %s!" % (Plural, Adj)
        return NStory

    if Story == 4:
        Relative = raw_input("Enter a relative: ")
        Noun = raw_input ("Enter noun: ")
        NStory = "My %s always said %s was like a box of %s. You never know what you're gonna get." % (Relative, Noun, Noun)
        return NStory

    if Story == 5:
        Time = raw_input("Enter a time of day: ")
        Verb = raw_input ("Enter verb: ")
        Noun = raw_input("Enter noun: ")
        NStory = "One %s, I %s a %s in my pajamas. How he got in my pajamas, I don't know." % (Time, Verb, Noun)
        return NStory

#Prints and calls new functions, also has raw_inputs
def main():
    CPop = raw_input("Please enter a population: ")
    CPop = int(CPop)
    NPop = CalcNewPopulation(CPop)
    NPop = int(NPop)
    print NPop

    Time = raw_input("Please enter a number of seconds: ")
    Time = int(Time)
    NTime = BreakoutTime(Time)
    print "Days: " + str(NTime[0])
    print "Hours: " + str(NTime[1])
    print "Minutes: " + str(NTime[2])
    print "Seconds: " + str(NTime[3])

    Sequence = raw_input("Please enter a DNA sequence: ")
    Codon = raw_input("Please enter a codon sequence: ")
    ListCodonPositions(Sequence, Codon)

    Story = raw_input ("Please choose which story you would like to use (1-5): ")
    Story = int(Story)
    NStory = MadLib(Story)
    print NStory




#Runs main
if __name__ == '__main__':
    main()
