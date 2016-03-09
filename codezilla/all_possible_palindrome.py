# Python program Find all distinct palindromic sub-strings
# of a given string
#from __future__ import print_function

# Function to print all distinct palindrome sub-strings of s
numbers = []  # Setup an empty list
final = []
don = []
def palindromeSubStrs(s):
	m = dict()
	n = len(s)

	# table for storing results (2 rows for odd-
	# and even-length palindromes
	R = [[0 for x in xrange(n+1)] for x in xrange(2)]

	# Find all sub-string palindromes from the given input
	# string insert 'guards' to iterate easily over s
	s = "@" + s + "#"

	for j in xrange(2):
		rp = 0 # length of 'palindrome radius'
		R[j][0] = 0

		i = 1
		while i <= n:

			# Attempt to expand palindrome centered at i
			while s[i - rp - 1] == s[i + j + rp]:
				rp += 1 # Incrementing the length of palindromic
						# radius as and when we find valid palindrome

			# Assigning the found palindromic length to odd/even
			# length array
			R[j][i] = rp
			k = 1
			while (R[j][i - k] != rp - k) and (k < rp):
				R[j][i+k] = min(R[j][i-k], rp - k)
				k += 1
			rp = max(rp - k, 0)
			i += k

	# remove guards
	s = s[1:len(s)-1]

	# Put all obtained palindromes in a hash map to
	# find only distinct palindrome
	m[s[0]] = 1
	for i in xrange(1,n):
		for j in xrange(2):
			for rp in xrange(R[j][i],0,-1):
				m[s[i - rp - 1 : i - rp - 1 + 2 * rp + j]] = 1
		m[s[i]] = 1

	# printing all distinct palindromes from hash map
	print "Below are " + str(len(m)) + " pali sub-strings"
	for i in m:
		#print i.strip("[],'")
		final.append(i.strip("[],'"))
		don = filter(lambda name: name.strip(), final)
		print don



# Python program to print all permutations with
# duplicates allowed
 
def toString(List):
    return ''.join(List)
 
# Function to print permutations of string
# This function takes three parameters:
# 1. String
# 2. Starting index of the string
# 3. Ending index of the string.
def permute(a, l, r):
    if l==r:
       # palindromeSubStrs( toString(a))
        numbers.append(toString(a))
    else:
        for i in xrange(l,r+1):
            a[l], a[i] = a[i], a[l]
            permute(a, l+1, r)
            a[l], a[i] = a[i], a[l] # backtrack
  
# Driver program to test the above function
string = "aaaabcde"
n = len(string)
a = list(string)
permute(a, 0, n-1)
  
# This code is contributed by Bhavya Jain


#for number in range(10):  # Loop over your numbers
#    numbers.append(number)  # Append the number to your list

#print (str(numbers))
# Driver program
#result = map(str.strip, numbers)
#line = numbers.rstrip("\n").split(";")
palindromeSubStrs(str(numbers))
# This code is contributed by BHAVYA JAIN and ROHIT SIKKA

