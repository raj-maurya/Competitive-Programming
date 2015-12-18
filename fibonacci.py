


#first, second, n = input().split()
def gets(*types):
    return tuple([types[i](val) for i, val in enumerate(input().split(' '))])
first, second, n = gets(int, int, int)


#first=int(input())

#second=int(input())
#inp = raw_input(" ")
#n= int(input())

for i in range (3,int(n)+1):
        k=second*second+first
        first=second
        second=k

print(int(k))
