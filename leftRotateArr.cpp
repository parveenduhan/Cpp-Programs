#include<iostream>
#include<vector>
using namespace std;

void leftRotateArr(vector<int> &arr, int l)
{
	int n = arr.size();
	for(int i = 0; i<l; i++)
	{
		int temp = arr[0];
		for(int j = 1; j<n; j++)
		{
			arr[j-1] = arr[j];
		}
		arr[n-1] = temp;
	}
	return ;
}

void leftRotateArrOpt(vector<int> &arr, int l)
{
	int n = arr.size();
	vector<int> temp;
	for(int i=0; i<l; i++)
		temp[i] = arr[i];
	for(int i = l; i<n; i++)
		arr[i-l] = arr[i];
	for(int i = 0; i<l;i++)
		arr[n-l+i] = temp[i];
	return ;
}

void reverse(vector<int> &arr, int si, int ei)
{
        if(si<ei)
        {
                int temp = arr[si];
                arr[si] = arr[ei];
                arr[ei] = temp;
                reverse(arr, si+1, ei-1);
                return ;
        }

        return;
}

void leftRotateArrOpt2(vector<int> &arr, int l)
{
	//reverse first l elements, then reverse remaining n-l elements and then finally reverse the whole array
	int n = arr.size();
	reverse(arr,0,l-1);
	reverse(arr, l, n-1);
	reverse(arr, 0, n-1);
	return ;
}


int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int l = 4; 
	cout<<"Original Arr: ";
	for(auto &ele : arr)
		cout<<ele<<" ";
	//leftRotateArr(arr, l);
	//leftRotateArrOpt(arr, l);
	leftRotateArrOpt2(arr, l);
	cout<<endl<<"Rotated Arr: ";
       for(auto &ele : arr)
       		cout<<ele<<" ";
	cout<<endl;       

	return 0;
}
