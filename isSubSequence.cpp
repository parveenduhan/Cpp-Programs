#include<iostream>
#include<string>
using namespace std;

bool isSubSequence(string& str1, string& str2)
{
	int n = str1.length()-1;
	int m = str2.length()-1;
	int j = 0;
	for(int i=0; i<n && j<m; i++)
	{
		if(str1[i] == str2[j])
			j++;
	}

	return (j==m);
}

int main()
{
	string str1, str2;
	cout<<"Enter first string: "<<endl;
	cin>>str1;
	cout<<"Enter second string: "<<endl;
	cin>>str2;
	cout<<"isSubSequence? "<<isSubSequence(str1, str2)<<endl;
	return 0;
}
		
