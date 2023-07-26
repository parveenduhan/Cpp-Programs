#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str = "aabbccddeeffgghhijklmnopqrsttuuvvwwxxyyzz";
	int arr[26] = {0};
	for(auto x: str)
		arr[x-'a']++;
	cout<<"String: "<<str<<endl;
	for(int i=0;i<26;i++)
		cout<<(char)('a'+i)<<": "<<arr[i]<<endl;

	return 0;
}













