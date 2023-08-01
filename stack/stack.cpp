#include<iostream>
#include<vector>
using namespace std;
#define N 10
class Stack
{
	private:
		vector<int> stk;
		int peak = -1;
	
	
	public:
		void push(int data)
		{
			this->stk.push_back(data);
			this->peak = data;
		}
		int pop()
		{
			if(this->isEmpty())
			{
				cout<<"stack is empty"<<endl;
				return 0;
			}
			int r = this->stk.back();
			this->stk.pop_back();
			this->peak = stk.back();
			return r;
		}
		int top()
		{
			if(this->isEmpty())
			{
				cout<<"stack is empty"<<endl;
				return 0;
			}
			return this->peak;
		}
		int size()
		{
			return this->stk.size();
		}
		bool isEmpty()
		{
			return this->stk.empty();
		}
};
class StackArr
{
	private:
		int *arr;
		int peak = -1;
	public:
		StackArr()
		{
			arr = new int[N];
		}

		void push(int data)
		{
			if(this->peak < N-1)
			{
				this->peak++;
				this->arr[this->peak] = data;
				
			}
			else
				cout<<"stack is already full, no further pushes allowed"<<endl;
		}
		int pop()
		{
			if(this->peak>=0)
			{
				return this->arr[this->peak--];
			}
			return -1;
		}
		int top()
		{
			if(this->peak>=0)
				return this->arr[this->peak];
			return -1;
		}
		int size()
		{
			return this->peak;
		}
		bool isEmpty()
		{
			if(this->peak>=0)
				return false;
			return true;
		}
};
class Node
{
	public:
	int data = -1;
	Node *next = nullptr;
	Node(int data)
	{
		this->data = data;
	}
};
class StackLL
{
	private:
		Node *peak = nullptr;
		int len = 0;
	public:
		void push(int data)
		{
			this->len++;
			Node *newNode = new Node(data);
			if(!peak)
				peak = newNode;
			else
			{
				newNode->next = this->peak;
				this->peak = newNode;
			}
		}
		int pop()
		{
			if (!this->peak)
			{
				cout<<"underflow"<<endl;
				return -1;
			}
			this->len--;
			int r = this->peak->data;
			this->peak = this->peak->next;
			return r;
		}
		int top()
		{
			if(this->peak)
				return this->peak->data;
			return -1;
		}
		int size()
		{
			return this->len;
		}
		bool isEmpty()
		{
			return this->len;
		}
};


int main()
{
	/*
	Stack *s = new Stack();
	s->push(10);
	s->push(20);
	s->push(30);
	cout<<s->pop()<<" " <<s->top()<<" " <<s->isEmpty()<<endl;
	*/
	StackLL *s = new StackLL();
	for(int i = 1; i<=10; i++)
	{
		s->push(10*i);
		cout<<"top: "<<s->top()<<" ";
		

	}
	cout<<endl<<"popping: "<<s->pop()<<"top: "<<s->top()<<endl;
       for(int i = 1; i<=10; i++)
       		cout<<"popping: "<<s->pop()<<" ";
	cout<<endl<<"checking underflow: "<<s->top()<<endl;
	
	return 0;
}


