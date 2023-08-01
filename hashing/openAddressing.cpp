#include<iostream>
#include<vector>
using namespace std; 
/*
 * In this program I'm using fixed size htable for doing some load_factor analysis however it can be made dynamically sized using vector instead of array.
 * I'm writing the program for storing only the keys, we can use an 2D array of m*2 to store key value pair or any other method as suitable. 
 * By NULL value I mean the slot is empty and by -1 I mean the slot is "deleted" to remove the issue with deletion and searching. 
*/
int index=-1;
class OpenAddrHash
{
	public:
		int *arr;
		int capacity; // total slots available in the htable
		int size; //total filled slots 
		OpenAddrHash(int c)
		{
			this->capacity = c;
			this->size = 0;
			this->arr = new int[capacity];
			for(int i=0; i<capacity; i++)
				this->arr[i] = NULL;
		}

		int hash1(int key)
		{
			return (key % (this->capacity));
		}
		
		int hash2(int key)
		{
			// Double-Hashing => (hash1(key) + i*hash2(key))%capacity, here 'i' is the probe count. 
			// We can have different implementations of hash2() considering that value returned by it is relatively prime to the capacity and it should not return zero. I have taken a sample hash2()
			
			return ((this->capacity -1) - (key % (this->capacity-1)));  // (6 - key % 6) if capacity is 7. 
		}

		bool search(int key)
		{
			int idx = this->hash1(key);
			int i = 0; //probe counter
			while(true)
			{
				if(this->arr[idx] == key)
				{
					index=idx;
					return true;
				}
				else if(this->arr[idx] != NULL)
				{
					
					idx =(this->hash1(key) + (++i)*(this->hash2(key))) % this->capacity; // idx = (hash1(key) + i*hash2(key))%capacity
				//	cout<<"key:"<<key<<", probe:"<<i<<"hash1:"<<this->hash1(key)<<", hash2:"<<this->hash2(key)<<", idx:"<<idx<<endl;
				}
				else
				{
					index=idx;
					return false; 
				}
					// if the condition of relatively not prime is violated, then the loop might reach infinite. 
			}
		}

		void insert(int key)
		{
			bool sFlag=this->search(key);
			int idx = index;
			if(sFlag == false)
			{
				this->arr[idx] = key;
			}
			return ;

		}

		void remove(int key)
		{
			bool sFlag=this->search(key);
			int idx = index;
			if(sFlag)
				this->arr[idx] = -1;
			return;
		}

};

int main()
{
	OpenAddrHash *htable = new OpenAddrHash(7);
	htable->insert(49);
	htable->insert(63);
	htable->insert(56);
	htable->insert(52);
	htable->insert(54);
	htable->insert(48);
	cout<<"Search(63):"<<htable->search(63)<<", Search(54):"<<htable->search(54)<<endl;
	for(int i = 0; i< htable->capacity; i++)
	       cout<<"idx:"<<i<<"key:"<<htable->arr[i]<<endl;
	
	htable->remove(63);
	htable->remove(54);
	cout<<"Seach(63):"<<htable->search(63)<<", Search(54):"<<htable->search(54)<<endl;
	return 0;
}
	



