l2 = [5, 20, 15, 20, 25, 50, 20]  #remove 20

def removeVal(sampleList, value):
    return[x for x in sampleList if x!=value]

answer2 = removeVal(l2, 20)
print(answer2)
