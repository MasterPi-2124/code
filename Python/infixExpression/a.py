import stack as ahihi
s=""
new_s=[]

def check(x, y):
    if (((x=='*'or x=='/') and (y=='+'or y=='-'))
    or ((x=='^') and (y=='+'or y=='-'))
    or ((x=='^') and (y=='*'or y=='/'))):
        return 1
    return 0

def toInfix(s):
    a=ahihi.stack()
    i=0
    while (i<len(s)):
        if (s[i].isdigit()):
            x=""
            j=i
            while ((j<len(s) and (s[j].isdigit()) or (j<len(s)-1 and s[j]=='.' and s[j+1].isdigit()))):
                x=x+s[j]
                j=j+1
            new_s.append(x)
            i=j-1
        elif (s[i]=='('):
            a.push(s[i])
        elif (s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'or s[i]=='^'):
            while (a.size() and not(check(s[i],a.top())) and a.top()!="("):
                new_s.append(a.top())
                a.pop()
            a.push(s[i])
        elif (s[i]==')'):
            while (a.top()=='+' or a.top()=='-' or a.top()=='*' or a.top()=='/' or a.top()=='^'):
                new_s.append(a.top())
                a.pop()
            if (a.top()=='('):
                a.pop()
        i=i+1
    while (a.size()):
        new_s.append(a.top())
        a.pop()
    return new_s

def Calculate(s):
    temp=ahihi.stack()
    i=0
    while (i<len(s)):
        if (s[i][0].isdigit()):
            d=float(s[i])
            temp.push(d)
        else:
            a1=temp.top()
            temp.pop()
            a2=temp.top()
            temp.pop()
            if (s[i]=="+"):
                temp.push(a1+a2)
            elif (s[i]=="-"):
                temp.push(a2-a1)
            elif (s[i]=="*"):
                temp.push(a1*a2)
            elif (s[i]=="/"):
                temp.push(a2/a1)
            elif (s[i]=="^"):
                temp.push(pow(a2,a1))
        i=i+1
    return temp.top()

fi=open("a.inp","r")
fo=open("a.out","w")
s=fi.readline()
for i in toInfix(s):
    fo.write(i)
    fo.write(" ")
fo.write("\n")
fo.write(str(Calculate(toInfix(s))))
