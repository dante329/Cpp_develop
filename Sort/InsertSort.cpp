//#include <iostream>
// 
//using namespace std;
//
//void InsertSort(int* arr,int sz)
//{
//	for(int i=2;i<=sz;i++)
//	{
//		int key = arr[i];
//		for(int j=i-1;j>=1;j--)
//		{
//			if(arr[j] > key) swap(arr[j],arr[j+1]); //这里相当于一直在用目标值做交换操作，虽然到最后也放到了正确的位置，但是并没有体现插入 
//		}		
//	}
//}
//
//void print(int* arr,int sz)
//{
//	for(int i=1;i<=sz;i++)
//	{
//		cout << *(arr+i) << " ";
//	}
//	cout << endl;
//}
//
//int main() 
//{
//	int n; cin >> n;
//	int arr[n];
//	for(int i=1;i<=sizeof(arr)/sizeof(int);i++)
//	{
//		arr[i] = i*i - 10*i + 10;
//	}
//	print(arr,sizeof(arr)/sizeof(int));
//	InsertSort(arr,sizeof(arr)/sizeof(int)); 
//	print(arr,sizeof(arr)/sizeof(int));
//	return 0;
//}
//

#include <iostream>
 
using namespace std;

void InsertSort(int* arr,int sz)
{
	for(int i=2;i<=sz;i++) //第一个元素默认有序 
	{
		int key = arr[i];
		int j = i-1;
		while(j >= 1 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}		
		//arr[j] = key;      //错误	 j位置的值是小于key的，所以我们要插入到j+1的位置上。在执行完挪位置的操作后j--让j多走了一步。
		arr[j+1] = key;  	//这就体现了直接插入的插入 
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
	InsertSort(arr,sizeof(arr)/sizeof(int)); 
	print(arr,sizeof(arr)/sizeof(int));
	return 0;
}
