/*  We can break any number(in our case it is the power represented by 'n') as a sum of powers of 2. For e.g. 10 => 8 +2; 19 => 16 + 2 + 1. 
 *  Using this logic on the value of 'n' we can break a large power such as 3^19 => 3^8 * 3^2 * 3^1. And if we see the binary representation of 19 => 10011, here we can assign a weight x^i where x is the base number and 2^0<=i<n; i will doubles with each bit moving from LSB to MSB such that 1(3^16), 0(3^8), 0(3^4), 1(3^2), 1(3^1). So basically we will keep doing square of x for each bit position in n and multiply x with result (initialised to 1) only when bit is 1. 
*/

#include<iostream>
using namespace std;
long int power(long int x,long int n)
{ 
	long int result = 1;
	while(n>0)
	{
		if(n%2 != 0)
			result = result*x;
		x = x*x;
		n = n>>1;
	}
	return result;
}
int main()
{
	long int x = 9;
	long int n = 19;
	cout<<power(x,n)<<endl;
	
	return 0;
}
