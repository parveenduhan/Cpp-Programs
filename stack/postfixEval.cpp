#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char op)
{
	return op == '+'|| op == '-'|| op == '*'|| op == '/';
}
int postfixEval(string str)
{
	stack<int> stk; 
	if(str.empty())
		return 0;
	for(auto x: str)
	{
		if(!isOperator(x))
			stk.push(x);
		else
		{
			int op2 = stk.top() - '0';
			stk.pop();
			int op1 = stk.top() - '0';
			stk.pop();

			switch(x)
			{
			case '+' : stk.push(op1 + op2);
				   break;
			case '-' : stk.push(op1 - op2);
				   break;
			case '*' : stk.push(op1*op2);
				   break;
			case '/' : stk.push(op1/op2);
				   break;
			default: break;
			}
			

		}
	}

	return stk.top();
}
int main()
{
	string postfix;
	getline(cin,postfix);

	cout<<"evaluation: "<<postfixEval(postfix)<<endl;

	return 0;
}
