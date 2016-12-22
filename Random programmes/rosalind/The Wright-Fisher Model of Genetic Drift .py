
from scipy.misc import comb

with open('rosalind_wfmd.txt') as input_data:
   N,m,g,k = [int(num) for num in input_data.read().strip().split()]

p_rec = 1.0 - (m/(2.0*N))

p = [comb(2*N, i)*((p_rec)**i)*(1.0-p_rec)**(2*N-i) for i in range(1,2*N+1)]

for gen in range(2,g+1):
   temp_p = []
   for j in range(1,2*N+1):
      temp_term = [comb(2*N, j)*((x/(2.0*N))**j)*(1.0-(x/(2.0*N)))**(2*N-j) for x in range(1,2*N+1)]
      temp_p.append(sum([temp_term[i]*p[i] for i in range(len(temp_term))]))
   p = temp_p


prob = sum(p[k-1:])
print prob
with open('WFMD.txt', 'w') as output_file:
     output_file.write(str(prob))
