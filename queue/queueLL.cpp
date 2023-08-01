#include<iostream>
using namespace std;


class Node
{
	public:
		int data;
		Node *next;
	
		Node(int data)
		{
			this->data = data;
			this->next = nullptr;
		}
};

class QueueLL
{
	private:
		int size;
		Node *front;
		Node * rear;

	public:
		QueueLL()
		{
			this->size = 0;
			this->front = nullptr;
			this->rear = nullptr;
		}

		bool is_empty()
		{
			return this->size == 0;
		}

		Node* get_front()
		{
			return this->front;
		}

		Node* get_rear()
		{
			return this->rear;

		}

		void enqueue(int x)
		{
		
			Node *new_node = new Node(x);
			if(this->rear)
				this->rear->next = new_node;
			this->rear = new_node;
			this->size++;
			if(!this->front)
				this->front = this->rear;
		}

		bool dequeue()
		{
			if(this->size == 0)
				return false;

			

			this->front = this->front->next;
			this->size--;
		}
		void print_queue()
		{
			Node *temp = this->front;
			while(temp)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};

int main()
{
	QueueLL *q = new QueueLL();
	for(int i = 0; i<10; i++)
		q->enqueue(10*i);

	q->print_queue();

	for(int i = 0; i<10; i++)
		q->dequeue();

	q->print_queue();

	q->dequeue();
	q->print_queue();

	return 0;
}



