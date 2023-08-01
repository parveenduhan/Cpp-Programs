#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOperator(char x)
{
	return x == '+' || x == '-' || x == '*' || x == '/';

}
int precedence(char op)
{
	if(op == '+' || op == '-')
		return 1;
	return 2;
}
char assoc(char op)
{
	return (op == '+' || op == '-') ? 'L':'R';
}
string infixToPostfix(string infix)
{
	stack<char> st;
	string ret = "";
	for(auto x: infix)
	{
		if(isOperator(x))						// returns 1 if x is an operator, 0 if paranthesis and -1 if x is an operand
		{
			if(st.empty())
				st.push(x);
			else
			{
				if(precedence(x)>precedence(st.top()))			//returns 1 if x > top, 0 if x <= top
						st.push(x);
				else if(precedence(x)<precedence(st.top()))
				{
					while((!st.empty()) && (precedence(x)<=precedence(st.top())))
					{
							ret += st.top();
							st.pop();
					}

					st.push(x);

				}
				else 
				{
					if(assoc(x) == 'L')
						st.push(x);
					else
					{
						while((!st.empty()) && (precedence(x) <= precedence(st.top())))
						{
							ret += st.top();
							st.pop();
						}
						st.push(x);
					}
				}
					
			}
		}
	


		else
		{
			if(x=='(')
				st.push(x);
			else if(x==')')
			{
				while(st.top() != '(')
				{
					ret += st.top();
					st.pop();
				}
				st.pop();
			}
			else
				ret += x;
		}
	}
	while(!st.empty())
			{
			ret += st.top();
			st.pop();
			}
	return ret;
}
int main()
{
	string str;
	getline(cin,str);
	str = infixToPostfix(str);
	cout<<str<<endl;

	return 0;
}
