#include<iostream>
#include<string>
using namespace std;

void robinKarpNaive(string &txt, string &pat)
{
	/*
	 * This function uses very simple method to compute hash, which is sum
	 * of ascii values of the pattern/text window. Thid might lead to multiple spurious mathes further leading to unneccesary char comparisons/
	 * For calculating hash value for current window of text, we are using
	 * rolling. Basically we are computng hash for current window based on 
	 * prev window using following formula:
	 * t(i+1) = t(i) + txt[i+m] - txt[i]
	 */

	int p = 0; // p will store hash value for the pattern
	int t = 0; // t will store hash value for current window of text
	
	int n = txt.length();
	int m = pat.length();
	//computing p
	for(int i = 0; i < m; i++)
	{
		p += (int) pat[i];
		t += (int) txt[i];
	}
	
	for(int i = 0; i <= n-m; i++)
	{
		bool flag = false;
		if(t == p)
			for(int j = 0; j<m; j++)
			{
				if(txt[i+j] != pat[j])
				{
					flag = false;
					break;
				}
				flag = true;
			}
		if(flag) 
			cout<<i<<" ";
		t += txt[i+m] - txt[i];

	}
}

void robinKarp(string &txt, string &pat)
{
	/*
	 * This function uses a slight complex method to compute hash values for pattern and text, Here we give weigtage to the the character position by assuming an variable preferebly having a prime value. For e.g h("abc"), ascii(a)*d^2 + ascii(b)*d^1 + ascii(c)*d^0
	 * For rolling, t(i+1) = d * (t(i) - txt[i] * d^(m-1) ) + txt[i+m]
	 */
	int p = 0;
	int t = 0;
	int d = 5; // An assumption
	int h  = 1;
	int n = txt.length();
	int m = pat.length();

	for(int i = 0; i< m-1; i++)
		h *= d; // computing d^m-1
	
	for(int i = 0; i < m; i++)
	{
		 p = p*d + (int) pat[i];
		 t = t*d + (int) txt[i];
	}

	for(int i = 0; i <= n-m; i++)
	{
		bool flag = false;
		if(t == p)
		{
			for(int j = 0; j < m; j++)
			{
				if(txt[i+j] != pat[j])
				{
					flag = false;
					break;
				}
				flag = true;
			}
		}
		if(flag)
			cout<<i<<" ";
		t = d * ( t - txt[i] * h) + txt[i+m];
	}
}



int main()
{
	string txt, pat;
	cout<<"Enter text: "<<endl;
	cin>>txt;
	cout<<"Enter pattern: "<<endl;
	cin>>pat;

//	robinKarpNaive(txt, pat);
	robinKarp(txt, pat);
	return 0;
}
