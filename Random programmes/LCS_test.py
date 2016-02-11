
# memoized, recursive LCS

def lcs(i, j, arr):   
    if i == "" or j == "":
        arr[len(i)][len(j)] = ""          # if empty array return ""
        return ""                   
    	
    elif i[-1] == j[-1]:                 #if last character is a match, find substring upto last and add last                                      	
        val = arr[len(i)-1][len(j)-1]    #check if array is already calculated, if not then calculate
        if val == 0:
            val = lcs(i[:-1], j[:-1], arr)
            arr[len(i)-1][len(j)-1] = val 
            
        val = val + i[-1]                #add calculated result and return it
        arr[len(i)][len(j)] = val 
        return val 
    else:                                # if last character is not same, find LCS of i,j upto last and so for j,i
       len_1 = arr[len(i)][len(j)-1]
       len_2 = arr[len(i)-1][len(j)]    
                                         # find the longest of these two strings and say it LCS if i, j
       if len_1 == 0:
           len_1 = lcs(i, j[:-1], arr)
           arr[len(i)][len(j)-1] = len_1
       if len_2 == 0:
           len_2 = lcs(i[:-1], j, arr)
           arr[len(i)-1][len(j)] = len_2
           
       if len(len_1) > len(len_2):
           val = len_1
       else:
           val = len_2             
       
       arr[len(i)][len(j)] = val         # return your stored value
       return val
        

   

p = (open('DNA_human.txt', 'r'))          # first text input file1.txt
k = (open('DNA_chimpanzee.txt', 'r'))     # second text file input file2.txt
i =str(p.read())
j = str(k.read())
arr = [[0 for _ in range(len(j)+1)] for _ in range(len(i)+1)]  
                                         #Call LCS
lcs(i,j,arr)
import sys
f = open('utput.txt', 'w')               #out put file output.txt
sys.stdout = f
                                        # store LCS of i,j i.e. two input files
print (arr [-1][-1])
