

print("------------------------------")
print("##"," ","Player","\tPoint")
print("------------------------------")
a=0
for line in lines:
    line=line.rstrip('\n')
    data = line.split(",")
    print(data[0], data[1], "\t",data[2])
    newScore = int(data[2])
    if newScore> a:
        a = newScore
        Name = data[1]
        Number = data[0]
print("------------------------------")
print("Top scorer:",Name,"#{}".format(Number), ", Points:",a)