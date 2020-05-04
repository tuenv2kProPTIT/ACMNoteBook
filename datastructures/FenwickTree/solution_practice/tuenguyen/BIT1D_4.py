from sys import stdin,stdout
class bit:
    def __init__(self,n):
        self.n=n
        self.f=[0]*(n+1)
    def update(self,pos,value):
        while pos <=self.n:
            self.f[pos]+=value
            pos+=(pos&-pos)
    def sum(self,pos):
        res=0
        while pos:
            res+=self.f[pos]
            pos-=(pos&-pos)
        return res
def unique(A):
    C=sorted(A)
    B=[]
    for element in C:
        if (not (B)) or B[-1]!=element:
            B.append(element)
    return B
n=int(stdin.readline())
A=[int(x)for x in stdin.readline().split()]
Atmp=[0]*n
Work=bit(n+10)
Map={}
for index in range(n-1,-1,-1):
    if A[index] in Map:
        Map[A[index]]+=1
    else:Map[A[index]]=1
    #print(Map[A[index]])
    Atmp[index]=(Map[A[index]])
    Work.update(Map[A[index]],1)

Map.clear()
ans=0
for i in range(n):
    if A[i] in Map:
        Map[A[i]]+=1
    else:Map[A[i]]=1
    
    Work.update(Atmp[i],-1)
    ans+=Work.sum(Map[A[i]]-1)
    #print(ans)
stdout.write("%d"%ans)
    