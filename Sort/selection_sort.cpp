#include <iostream>
 
using namespace std;

void selection_sort(int* arr,int sz)
{
	for(int i=1;i<=sz;i++) //第一个元素默认有序 
	{
		int mini = i; 
		for(int j=i;j<=sz;j++)
		{
			if(arr[j] < arr[mini])
			{
				mini = j;
			}
		}
		swap(arr[i],arr[mini]); 
	}
}

void print(int* arr,int sz)
{
	for(int i=1;i<=sz;i++)
	{
		cout << *(arr+i) << " ";
	}
	cout << endl;
}

int main() 
{
	int n; cin >> n;
	int arr[n];
	for(int i=1;i<=sizeof(arr)/sizeof(int);i++)
	{
		arr[i] = i*i - 10*i + 10;
	}
	print(arr,sizeof(arr)/sizeof(int));
	selection_sort(arr,sizeof(arr)/sizeof(int)); 
	print(arr,sizeof(arr)/sizeof(int));
	return 0;
}
