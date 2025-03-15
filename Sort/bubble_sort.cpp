#include <iostream>
 
using namespace std;

//void bubble_sort(int* arr,int sz)
//{
//	for(int i=sz;i>1;i--) //n-1ÌË 
//	{
//		for(int j=1;j<i;j++)
//		{
//			if(arr[j]>arr[j+1])
//			{
//				swap(arr[j],arr[j+1]);
//			 } 
//		}
//	 } 
//}

//ÓÅ»¯ Ë³ĞòO(n) ÄæĞòO(n^2) 
void bubble_sort(int* arr,int sz)
{
	for(int i=sz;i>1;i--) //n-1ÌË 
	{
		int flag = 1;
		for(int j=1;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag = 0;
			 } 
		}
		if(flag) break;
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
	bubble_sort(arr,sizeof(arr)/sizeof(int)); 
	print(arr,sizeof(arr)/sizeof(int));
	return 0;
}
