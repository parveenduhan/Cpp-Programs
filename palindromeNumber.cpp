#include<iostream>
using namespace std;
bool brutPalindrome(int n)
{
	int copy = n;
	int arr[10] = {0}; // we can have maximum 10 digits in a 4byte signed integer
	int n2 = 0;
	int temp1 = 0 ;
	int temp2 = 1;
	while(n>0)
	{
		temp1 = n % 10;
		n2 += temp1*temp2;
		
		temp2 = temp2*10;
		n /=10;
	}
	return (copy == n2);
}
	
int main()
{
	int n = 78987;
	cout<<brutPalindrome(n)<<endl;

	return 0;
}
