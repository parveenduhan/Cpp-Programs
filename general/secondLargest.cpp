#include<iostream>
#include<vector>
using namespace std;

int secondLargest(vector<int> arr)
{
	int res = -1,largest = 0;
	int n = arr.size();
	for(int i=0; i<n;i++)
	{
		if(arr[i]>arr[largest])
		{
			largest = i;
			res = largest;
		}
		else
		{
			if(res != -1 && arr[i]>arr[res])
				res = i;
		}
	}

	return res;
}
int main()
{
	vector<int> arr = {12, 2, 10, 12, 20, 36, 20, 36};
	int n = arr.size();
	cout<<"Arr: ";
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"Second Largest is: "<<secondLargest(arr)<<endl;

	return 0;
}

