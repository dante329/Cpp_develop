#include <bits/stdc++.h>
using namespace std;

int main()
{
	char ch[10] = "abcdef";
	cout << sizeof ch;
}


//int main()
//{
//	int num_count=0; 
//	int m,n;
//	cin >> m >> n;
//	int pic1[m][n],pic2[m][n];
//	for(int i=0;i<m;++i)
//	{
//		for(int j=0;j<m;++j)
//		{
//			cin >> pic1[i][j];
//		}
//	}
//	for(int i=0;i<m;++i)
//	{
//		for(int j=0;j<m;++j)
//		{
//			cin >> pic2[i][j];
//		}
//	}
//	for(int i=0;i<m;++i)
//	{
//		for(int j=0;j<m;++j)
//		{
//			if(pic1[i][j]==pic2[i][j])
//			{
//				++num_count;
//			}
//		}
//	}
//	cout << fixed << setprecision(2) << ((double)num_count/(m*n))*100; 
//	return 0;
//}


//����ģ���ֵ��������������һ�����޸ĵ���ֵ����arr1��arr2������ֵ  arr1=&a[row1],&arr2=&a[row2]
//���Ҿ�̬���ٵ������ַ���������ģ���ʹ������Ҳû�á��� C++ �У���̬����Ķ�ά�����������洢�ģ�arr1[row1] �� arr2[row2] �ֱ��ʾ�����е��׵�ַ����Щ��ַ���ڴ����ǹ̶��ģ��޷�ͨ����ֵ���ġ�
//void Swap(int (*)[5] arr1,int (*)[5] arr2)	//�����������Ͳ���ʹ��auto 
//{
//	int* tmp = *arr1;
//	*arr1 = *arr2;
//	*arr2 = tmp; 
//}

//int main() {
//    int a[5][5];
//
//    // ���� 5x5 ����
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            cin >> a[i][j];
//        }
//    }
//
//    // ������Ҫ����������
//    int A1, A2; 
//    cin >> A1 >> A2;
//    
//	int row1 = A1-1, row2 = A2-1;	
////    // ����кźϷ���
////    if (row1 < 0 || row1 >= 5 || row2 < 0 || row2 >= 5) {
////        cout << "Invalid row indices!" << endl;
////        return 1;
////    }
//
//    // ����������
//    int tmp[5];
//    for (int j = 0; j < 5; ++j) {
//        tmp[j] = a[row1][j];
//    }
//    for (int j = 0; j < 5; ++j) {
//        a[row1][j] = a[row2][j];
//        a[row2][j] = tmp[j];
//    }
//
//    // ���������ľ���
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

//int main()
//{
//	int a[5][5];
//	for(int i=0;i<5;++i)
//	{
//		for(int j=0;j<5;++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	
//	int row1,row2;
//	cin >> row1 >>row2;
//
////ǳ�������ں��������У�tmp[j] ���ʵ�ʵ�������Ѿ����޸Ĺ��� a[row1][j] 
////	int* tmp = a[row1];
////	for(int j=0;j<5;++j)
////	{
////		a[row1][j] = a[row2][j];
////	}
////	for(int j=0;j<5;++j)
////	{
////		a[row2][j]=tmp[j];
////	}	
//
//	int tmp[5];
//	for (int j = 0; j < 5; ++j) {
//	    tmp[j] = a[row1][j];
//	}
//	for (int j = 0; j < 5; ++j) {
//	    a[row1][j] = a[row2][j];
//	    a[row2][j] = tmp[j];
//	}
//
//	for(int i=0;i<5;++i)
//	{
//		for(int j=0;j<5;++j)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//	int* tmp = arr;
//	for(int i=0;i<5;++i)
//	{
//		cout << tmp[i];
//	}
//	return 0;
// } 








//int main() 
//{
//	int n;
//	cin >> n;
//	int arr[n][n];
//	memset(arr,0,sizeof(arr));
//	for(int i=0;i<n;++i)
//	{
//		for(int j=0;j<=i;++j)
//		{
//			if(j==0||j==i)
//			{
//				arr[i][j] =1;				
//			}
//			else
//			{
//				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//			}
//		}
//	}
//	for(int i=0;i<n;++i)
//	{
//		for(int j=0;j<=i;++j)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
