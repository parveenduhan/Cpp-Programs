#include<iostream>
#include<vector>
using namespace std;

bool isArrSorted(vector<int> arr, int n)
{
	if(n <= 0)
		return false;
	if(n == 1 )
		return true;
		
	return (isArrSorted(arr, n-1) && arr[n-1] <= arr[n]);
}
int main()
{
	vector<int> arr = {3, 4, 5, 6, 7};
	int n = arr.size();
	cout<<"Sorted: "<<isArrSorted(arr, n-1)<<endl;

	return 0;
}


