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
//    int total_drinks = n;   // 初始的饮料数量
//    int caps = n;           // 初始的瓶盖数量
//
//    // 不断兑换瓶盖，直到无法再兑换
//    while (caps >= 3) {
//        int new_drinks = caps / 3;  // 可以兑换的新饮料数量
//        total_drinks += new_drinks;  // 更新总饮料数量
//        caps = caps % 3 + new_drinks;  // 更新瓶盖数量：剩下的瓶盖 + 新获得的瓶盖
//    }
//
//    cout << total_drinks << endl;
//    return 0;
//}

//写的一坨狗屎 
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
 
//递归 
int Count(int caps)
{	
	if(caps<3)	//现在用的参数是瓶盖的数量，caps<3不能兑换饮料 
	{
		return 0;
	}
	int exchange_bottles = n/3; //新换的饮料 
	int remain_caps = n%3; //换完剩下的瓶盖 
	int total_caps = exchange_bottles + remain_caps; //目前能兑换的所有的瓶盖 
	return exchange_bottles + Count(total_caps); //传入n，返回能用n换的饮料数+所有瓶盖能兑换的饮料数（递归） 
}
int n;
int main()
{
	cin >> n;
	cout << n + Count(n);
} 

//int count_drinks(int caps) {
//    if (caps < 3) {
//        return 0;  // 如果瓶盖数小于3，不能换饮料
//    }
//
//    // 用瓶盖换饮料：每3个瓶盖可以换1瓶饮料
//    int new_drinks = caps / 3;
//    // 剩余的瓶盖是当前瓶盖数除以3的余数，再加上用瓶盖换来的新瓶盖
//    int remaining_caps = caps % 3 + new_drinks;
//
//    // 返回已喝的饮料数 + 递归计算剩余瓶盖可以换的饮料
//    return new_drinks + count_drinks(remaining_caps);
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    // 初始购买了 n 瓶饮料，开始有 n 个瓶盖
//    // 总共喝到的饮料数 = 初始饮料数 + 用瓶盖换的饮料数
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
