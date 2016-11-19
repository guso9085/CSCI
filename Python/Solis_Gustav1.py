
def Bill(Days):
    BAmount = 0
    BAmount = BAmount + (Days * 100)
    return BAmount

def John(Days):
    JAmount = 0
    for i in range(Days):
        JAmount = JAmount + (1000 / (2 ** i))
    return JAmount

def Kate(Days):
    KAmount = 0
    for i in range(Days):
        KAmount = KAmount + (0.01 * (2 ** i))
    return KAmount

def main():
    Days = raw_input("Please enter a number of days: ")
    Days = int(Days)
    BAmount = Bill(Days)
    JAmount = John(Days)
    KAmount = Kate(Days)
    if (BAmount > JAmount) and (BAmount > KAmount):
        print "Bill"
    if (JAmount > BAmount) and (JAmount > KAmount):
        print "John"
    if (KAmount > BAmount) and (KAmount > JAmount):
        print "Kate"


if __name__ == '__main__':
    main()
