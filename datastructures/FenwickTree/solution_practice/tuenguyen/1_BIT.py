from sys import stdin,stdout
n=int(stdin.readline())
A=[int(x)for x in stdin.readline().split()]
Map={}
s=0
pres=0
for index,element in enumerate(A):
    s+=element*index-pres
    pres+=element
    if (element-1) in Map:
        s-=Map[element-1]
    if (element+1) in Map:
        s+=Map[element+1]
    if element in Map:
        Map[element]+=1
    else :Map[element]=1
stdout.write("%d"%s)