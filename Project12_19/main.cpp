#include <iostream>
#include <cstring>
using namespace std;

//int main()
//{
//	int init_bottle;
//	cin >> init_bottle;
//	int caps = init_bottle;
//	int sum = init_bottle;
//	while(caps>=3)
//	{
//		int exchange = caps/3;
//		int remain_caps = caps%3;
//		sum += exchange;
//		caps = exchange + remain_caps;
//	}
//	cout << sum;
//	
//	return 0;
//}



//int main() {
//    int n;
//    cin >> n;
//
//    int total_drinks = n;   // ��ʼ����������
//    int caps = n;           // ��ʼ��ƿ������
//
//    // ���϶һ�ƿ�ǣ�ֱ���޷��ٶһ�
//    while (caps >= 3) {
//        int new_drinks = caps / 3;  // ���Զһ�������������
//        total_drinks += new_drinks;  // ��������������
//        caps = caps % 3 + new_drinks;  // ����ƿ��������ʣ�µ�ƿ�� + �»�õ�ƿ��
//    }
//
//    cout << total_drinks << endl;
//    return 0;
//}

//д��һ�繷ʺ 
//int main()
//{
//	int n;
//	cin >> n;
//	int exchange = n;
//	int sum = n; 
//	int rem = n;
//	while(exchange>=3)
//	{		
//		exchange = rem/3;
//		rem = n%3;
//		sum += exchange;
//	
//	}
//	cout << sum;
//	return 0;
// } 
 
//�ݹ� 
int Count(int caps)
{	
	if(caps<3)	//�����õĲ�����ƿ�ǵ�������caps<3���ܶһ����� 
	{
		return 0;
	}
	int exchange_bottles = n/3; //�»������� 
	int remain_caps = n%3; //����ʣ�µ�ƿ�� 
	int total_caps = exchange_bottles + remain_caps; //Ŀǰ�ܶһ������е�ƿ�� 
	return exchange_bottles + Count(total_caps); //����n����������n����������+����ƿ���ܶһ������������ݹ飩 
}
int n;
int main()
{
	cin >> n;
	cout << n + Count(n);
} 

//int count_drinks(int caps) {
//    if (caps < 3) {
//        return 0;  // ���ƿ����С��3�����ܻ�����
//    }
//
//    // ��ƿ�ǻ����ϣ�ÿ3��ƿ�ǿ��Ի�1ƿ����
//    int new_drinks = caps / 3;
//    // ʣ���ƿ���ǵ�ǰƿ��������3���������ټ�����ƿ�ǻ�������ƿ��
//    int remaining_caps = caps % 3 + new_drinks;
//
//    // �����Ѻȵ������� + �ݹ����ʣ��ƿ�ǿ��Ի�������
//    return new_drinks + count_drinks(remaining_caps);
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    // ��ʼ������ n ƿ���ϣ���ʼ�� n ��ƿ��
//    // �ܹ��ȵ��������� = ��ʼ������ + ��ƿ�ǻ���������
//    cout << n + count_drinks(n) << endl;
//
//    return 0;
//}

//void Swap(int* p1,int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp; 
//}
//
//void BubbleSort(int* a,int n)
//{
//	for(int i = 0; i<n; ++i)
//	{	
//		for(int j = 1; j<n-i; ++j)
//		{
//			if(a[j-1]>a[j])
//			{
//				Swap(&a[j-1],&a[j]);
//			} 
//		}
//	}
//	 
//}
//
//void TestBubbleSort()
//{
//	int a[] = {3,54,78,9,2,12,0,4,87,56,34};
//	BubbleSort(a,sizeof(a)/sizeof(int));
//	for(int i:a)
//	{
//		cout << i << " ";
//	}
//}
//
//int main()
//{
//	TestBubbleSort(); 
// 	return 0;
// } 

//int main()
//{
//	int arr1[10] = {1,2,3,4,5,6,7,8};
//	int arr2[10] = {0};
//	memcpy(arr2,arr1,sizeof(arr1));
//	for(int i:arr2)
//	{
//		cout << i << " ";
//	}
// 	return 0;
// } 

//void Swap(auto* a,auto* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//} 
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(&a,&b);
//	cout << a << " " << b;
//	return 0;
//}


//int main()
//{
//	char ch[] = "hello world";
//	int arr[] = {1,2,3,4,5,6,7,8} ;
//	for(int i : arr)
//	{
//		cout << i << " " ; 
//	}
//	cout << arr  ;
//	return 0;
//}

//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8} ;
//	memset(arr,1,sizeof(arr));
//	for(int i : arr)
//	{
//		cout << i << " " ; 
//	}
//	return 0;
//}




//int n,aim,index,flag;
//int main()
//{
//    cin >> n;
//    int arr[n];
//    for(int i=0;i<n;++i)
//    {
//        cin >> arr[i];
//    }
//    cin >> aim;
//    for(int i=0;i<n;++i)
//    {
//        if(aim == arr[i])
//        {
//            flag =1;
//            index =i;
//            break;
//        }
//    }
//    if(flag == 0)
//    {
//        index = -1;
//    }
//    cout << index;
//    return 0;
//}
