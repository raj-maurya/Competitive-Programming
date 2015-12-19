
first=1
second=2
t=int(input())
a=[]
for i in range (1,t+1):
    m=input()
    a.append(m)
#first=int(input())

#second=int(input())
#inp = raw_input(" ")
#n= int(input())
l=0
num=[a]
for j in range (1, t+1):
  for i in  num:
        k=second+first
        first=second
        second=k
        print(int(k))
        if(k%2==0 and k<num):
         l=l+k

print(l+2)
        
