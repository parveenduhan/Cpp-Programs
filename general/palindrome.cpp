#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string str)
{
	int i = 0, j = str.length()-1;
	while(i<j)
	{
		if(str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}
bool isPal(string str)
{
	
	

		if(str == "" || str.length() == 1)
			return true;
		if(str[0] == str[str.length()-1])
			str = str[0,str.length()-1];
			return isPal(str);
		
	
	return false;
	
}
int main()
{
	string str;
	cout<<"enter a string: "<<endl;
	cin>>str;
//	cout<<"isPalindrome? "<<isPalindrome(str)<<endl;
	cout<<"isPal? "<<isPal(str)<<endl;
	cout<<"string: "<<str<<endl;	
	return 0;
}
