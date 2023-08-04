#include<iostream>
#include "gcd.h"
using namespace std;

int lcmBrut(int a, int b)
{	//lcm --> least common multiplier, which means the least number which is a multiple of both a and b hence lcm(a,b) will always be equal to greater than the largest of two
	
	int res = (a>b)? a: b;
	while(true)
	{
		if(res % a == 0 && res % b == 0)
			return res;
		
		res++;
	}
}

int lcmOpt(int a, int b)
{
	// We know, a*b == gcd(a,b) * lcm(a,b)
	
	return (a*b)/gcdEuclidOpt(a,b);
}
int main()
{
	int a = 24, b = 10;
	 
	cout<<"lcmBrut:"<<lcmBrut(a,b)<<endl<<"lcmOptimized:"<<lcmOpt(a,b)<<endl;

	return 0;
}


