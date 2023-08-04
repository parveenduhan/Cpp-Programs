#include<iostream>
#include<vector>
using namespace std;

//In this program, by difference I mean arr[j]-arr[i] where j>i always hence we can have positive and negative differences and I am  using real number line for comparing the differences. There can be multiple ways to solve the problem but I'm using a method which achieves the task in O(n) time and space.
//O(n^2) => consider every pair of integers and check their difference
//O(nlogn) => use merge sort and then find arr[n-1] - arr[0]. 
//O(n) => Inspired from above mentioned 2nd method.
//
int maxDifference(vector<int> arr)
{
	int n = arr.size();
	int min = arr[0], res = arr[1] - arr[0];
	for(int i = 1; i<n; i++)
	{
		res = (res >(arr[i] - min))? res : (arr[i] - min);
	       min = (min > arr[i])? arr[i] : min;
	}
	return res;
}
int main()
{
	vector<int> arr = { 2, 3, 10, 6, 4, 8, 1};
	cout<<"Arr: ";
	for(auto &ele: arr)
		cout<<ele<<" ";
	cout<<endl<<"Max Difference: "<<maxDifference(arr)<<endl;
	
	return 0;
}
