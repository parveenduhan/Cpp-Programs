#include<iostream>
#include<string>
using namespace std;
/*
 * algorithm can be optimized in terms of time complexity by passing string lengths as arguments instead of using substr function which give extra overhead of O(n) */
bool isSubSequence(string str1, string str2)
{
	if(str1.length() < str2.length())
		return false;

	if(str1[0] == str2[0])
	{
		if(str2.length() == 1)
			return true;
		else 
		{
			str1 = str1.substr(1);
			str2 = str2.substr(1);
			return isSubSequence(str1, str2);
		}
	}
	else
	{
		str1 = str1.substr(1);
		return isSubSequence(str1, str2);
	}
}
int main()
{
	string str1, str2;
	cout<<"Enter String1 "<<endl;
	cin>>str1;
	cout<<"Enter String2 "<<endl;
	cin>>str2;
	cout<<"isSubSequnce? "<<isSubSequence(str1,str2)<<endl;

	return 0;
}
