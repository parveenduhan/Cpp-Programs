#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int countDistEle(vector<int> v)
{
	unordered_set s(v.begin(), v.end());
       return s.size();
}
int main()
{
	vector<int> v;
	for(int i=0; i<10;i++)
		if(i<5)
			v.push_back(i);
		else
			v.push_back(i/3);
	cout<<"<Arr: ";
	for(auto ele:v)
	{
		cout<<ele<<" ";
	}
	cout<<endl<<"Num Of Distinct Elements: "<<countDistEle(v)<<endl;
	return 0;
}
