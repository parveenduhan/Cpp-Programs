#include<iostream>
#include<vector>
using namespace std;
class Queue
{
	private:
		int rear;
		int front;
		int cap;
		int size ;
		int *queue;

	public:
		Queue(int cap)
		{
			this->cap = cap;
			this->queue = new int[this->cap];
			this->rear = 0;
			this->front = 0;
			this->size = 0;
		}
		bool is_empty()
		{
			return this->size == 0;
		}

		bool is_full()
		{
			return this->size == this->cap;
		}
		
		int get_rear()
		{
			if(is_empty())
				return -1;
			return (this->front + this->size -1);
		}

		int get_front()
		{
			if(this->is_empty())
				return -1;
			return this->front;
		}

		bool enqueue(int data)
		{
			if(this->is_full())
				return false;

			this->rear = this->get_rear();

			this->rear = (this->rear+1)%this->cap;
			this->queue[this->rear] = data;
			this->size++;

			return true;
		}

		bool dequeue()
		{
			if(is_empty())
				return false;
			
			this->front = (this->front +1 ) % this->cap;
			this->size--;

			return true;
						

		}

};
int main()
{
	Queue *q = new Queue(10);
	for(int i = 0; i<10; i++)
	{
		q->enqueue(10*i);
	}
	for(int i = 0; i<11;i++)
	{
		cout<<"deq "<<q->dequeue()<<endl;
		cout<<"front "<<q->get_front()<<endl;
		cout<<"rear "<<q->get_rear()<<endl;
	}

	return 0;
}
