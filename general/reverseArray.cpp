#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr, int si, int ei)
{

	if(si<ei)
	{
		int temp = arr[si];
		arr[si] = arr[ei];
		arr[ei] = temp;
		reverseArray(arr, si+1, ei-1);
		return ;
	}

	return;
}
int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	cout<<"Original Arr: ";
	for(auto &ele : arr)
		cout<<ele<<" ";

	reverseArray(arr, 0, arr.size() -1);
	cout<<endl<<"ReversedArr: ";

	for(auto &ele : arr)
		cout<<ele<<" ";

	return 0;
}
