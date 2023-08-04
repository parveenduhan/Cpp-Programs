#include<iostream>
#include<string>
using namespace std;

void patternSearch(string &txt, string &pat)
{
	int n = txt.length();
	int m = pat.length();
	for(int i = 0; i <= (n-m); i++)
	{
		int j;
		for(j = 0; j < m; j++)
		{
			if(pat[j] != txt[i+j])
				break;
		}
		if(j == m)
			cout<<i<<" ";
	}
}
int main()
{
	string txt, pat;
	cout<<"Enter the text: "<<endl;
	cin>>txt;
	cout<<"Enter the pattern: "<<endl;
	cin>>pat;

	patternSearch(txt, pat);
	
	return 0;
}
