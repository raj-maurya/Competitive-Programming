#include <iostream>
#include <vector>
using namespace std;
/*The total number of rabbit pairs that will be present after n months
* if each pair of reproduction-age rabbits produces a litter of k rabbit
* pairs in each generation (instead of only 1 pair).
* */
vector<double> fib(int n, int k)
{
vector<double> fib_table(n);
for(int i = 0; i < n; i++)
{
if (i == 0 or i == 1) fib_table[i] = 1;
else fib_table[i] = fib_table[i-1] + k*fib_table[i-2];
}
return fib_table;
}
int main()
{
int n, k = 0;
cin >> n >> k;
vector<double> fib_table = fib(n, k);
cout << "The total number of rabbit pairs is: " << fib_table[n-1] << endl;
}
