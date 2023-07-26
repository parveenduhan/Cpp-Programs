#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string &str1, string &str2)
{
	vector<int> v(256,0);
	
	int n = str1.length()-1;
	int m = str2.length() -1;
	if(n!=m)
		return false;
	for(int i = 0; i<=n; i++)
	{
		v[(int)str1[i]]++;
		v[(int)str2[i]]--;
	}

	for(int i =0; i<v.size()-1;i++)
	{
		if(v[i] != 0)
			return false;
	}
	return true;
}
int main()
{
	string str1, str2;
	cout<<"Enter first string: "<<endl;
	cin>>str1;
	cout<<"Enter second string: "<<endl;
	cin>>str2;
	cout<<"isAnagram? "<<isAnagram(str1, str2)<<endl;

	return 0;
}

