#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool balancedParanthesis(string str)
{
	if(str.length()!= 0)
	{
		stack<char> s;
		for(auto i: str)
		{
			switch(i)
			{
			case '(' : s.push(i);
				   continue;
			case '[' : s.push(i);
				   continue;
			case '{' : s.push(i);
				   continue;
			case ')' : if('(' == s.top()){ s.pop(); continue;} 
					   else
						   break;

			case ']' : if('[' == s.top()){s.pop(); continue;} 
					   else
						   break;
			case '}' : if('{' == s.top()) { s.pop(); continue;}
					   else
						   break;
			default :
				   break;
			}	  
			return false;
			
		}
		return s.empty();
	}
	return true;
}
int main()
{
	string str;
	getline(cin,str);
	cout<<balancedParanthesis(str)<<endl;

	return 0;
}

			
