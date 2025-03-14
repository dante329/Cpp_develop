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
//			if(arr[j] > key) swap(arr[j],arr[j+1]); //�����൱��һֱ����Ŀ��ֵ��������������Ȼ�����Ҳ�ŵ�����ȷ��λ�ã����ǲ�û�����ֲ��� 
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
	for(int i=2;i<=sz;i++) //��һ��Ԫ��Ĭ������ 
	{
		int key = arr[i];
		int j = i-1;
		while(j >= 1 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}		
		//arr[j] = key;      //����	 jλ�õ�ֵ��С��key�ģ���������Ҫ���뵽j+1��λ���ϡ���ִ����Ųλ�õĲ�����j--��j������һ����
		arr[j+1] = key;  	//���������ֱ�Ӳ���Ĳ��� 
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
