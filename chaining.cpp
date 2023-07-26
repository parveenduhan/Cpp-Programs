#include<iostream>
#include<list>
using namespace std;
/* I have taken size of the hash table from user, hash table can be made dynamically sized by using dynamic size data structure such as vector of lists instead of array of lists. */
class HashChaining
{
public:
	int size = 0;
	list<int> *htable;
	
	HashChaining(int size)
	{
		this->size = size;
		this->htable = new list<int> [size];
	}
	bool search(int key)
	{
		int i = key % this->size;
		for(auto x: this->htable[i])
		{
			if(x == key)
				return true;
		}
		return false;
	}

	void insert(int key)
	{
		int i = key % this->size;
		this->htable[i].push_back(key);
	}
	void remove(int key)
	{
		int i = key % this->size;
		this->htable[i].remove(key);
	}
	};

int main()
{
HashChaining *htable1 = new HashChaining(7);
htable1->insert(14);
htable1->insert(22);
htable1->insert(30);
htable1->insert(38);
htable1->insert(46);
htable1->insert(54);
htable1->insert(62);
htable1->insert(63);
htable1->insert(4);
htable1->insert(3);
htable1->insert(2);
htable1->insert(1);
htable1->insert(5);
htable1->insert(6);
htable1->insert(7);
htable1->insert(8);
htable1->insert(15);
cout<<"ht(14):"<<htable1->search(14)<<", ht(62):"<<htable1->search(62)<<endl;
htable1->remove(14);
htable1->remove(62);
cout<<"ht(14):"<<htable1->search(14)<<", ht(62):"<<htable1->search(62)<<endl;
cout<<"ht(7):"<<htable1->search(7)<<", ht(6):"<<htable1->search(6)<<endl;

return 0;

}
