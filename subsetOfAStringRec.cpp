#include<iostream>
#include<string>
using namespace std;

void subsetOfAString(string str, string curr = "", int i = 0)
{
	if(i == str.length())
	{
		cout<<curr<<", ";
		return;
	}
	subsetOfAString(str, curr, i+1); // 
	subsetOfAString(str, curr+str[i], i+1);
	return;
}

int main()
{
	string s = "ABCD";
	subsetOfAString(s);
	
	return 0;
}
