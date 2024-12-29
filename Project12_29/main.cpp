#include <iostream>
#include <string>
using namespace std;

string s = "0123456789ABCDEF"; 

string str; 

void x_to_m(int x,int m)
{
	if(x>=m)
	{
		x_to_m(x/m,m);
	}
	str =str + s[x%m];
}

int main()
{
	int x,m;
	cin >> x >> m;
	x_to_m(x,m);
	cout << str;
	return 0;
} 


//int main()
//{
//	double x = 5;
//	double ret = x/2;
//	printf("%.2f",ret);
//	return 0;
//} 

//double fun(int x,int n)
//{
//	if(n == 1)
//		return x/(1+x);
//	else
//		return x/(n+fun(x,n-1));
//}
//
//int main()
//{
//	double x;
//	int n;
//	cin >> x >> n;
//	printf("%.2f",fun(x,n));
//
//	return 0;
//} 


//double fun(int x,int n)
//{
//	if(n == 1)
//		return sqrt(1+x);
//	else
//		return sqrt(n+fun(x,n-1));
//}
//
//int main()
//{
//	double x;
//	int n;
//	cin >> x >> n;
//	printf("%.2f",fun(x,n));
//	
//	return 0;
// } 


//int digit(int n,int k)
//{
//	if(k == 1)
//		return n%10; 
//	else
//	
//}
//
//int main()
//{
//	int n,k;
//	cin >> n >> k;
//	cout << digit(n,k) << endl; 	
//	return 0;
// } 


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int digit(int n,int k)
//{
//	n = n/pow(10,k-1);
//	return n%10;
//}
//
//int main()
//{
//	int n,k;
//	cin >> n >> k;
//	cout << digit(n,k) << endl; 	
//	return 0;
// } 

//int akm(int m,int n)
//{
//	if(m==0)
//		return n+1;
//	if(m>0 && n==0)
//		return akm(m-1,1);
//	if(m>0 && n>0)
//		return akm(m-1,akm(m,n-1));
//}
//
//int main()
//{
//	int m,n;
//	cin >> m >> n;
//	int ret = akm(m,n);
//	cout << ret <<endl;
//	return 0;
// } 


//// 判断是否是素数
//bool prime(int n)
//{
//    if (n <= 1) return false;
//    if (n == 2 || n==3) return true;
//    if (n % 2 == 0 || n % 3 == 0) return false;
//    for (int i = 5; i * i <= n; i += 6) // 进一步优化
//    {
//        if (n % i == 0 || n % (i + 2) == 0)
//            return false;
//    }
//    return true;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    
//    int arr[5000];  // 存放素数
//    int j = 0;
//    
//    // 查找所有小于等于n的素数
//    for (int i = 1; i <= n; ++i)
//    {
//        if (prime(i)) 
//            arr[j++] = i;
//    }
//
//    // 存放素数对
//    int arr2[2500];  
//    int l = 0;
//
//    // 查找所有相差为2的素数对
//    for (int i = 0; i < j - 1; ++i)  // 注意: j - 1, 防止 arr[i+1] 越界
//    {
//        if (arr[i+1] - arr[i] == 2)
//        {
//            arr2[l++] = arr[i];      // 存放第一个素数
//            arr2[l++] = arr[i+1];    // 存放第二个素数
//        }
//    }
//
//    // 输出素数对
//    for (int i = 0; i < l; i += 2)
//    {
//        cout << arr2[i] << " " << arr2[i+1] << endl;
//    }
//    
//    return 0;
//}
//

//#include <iostream>
//using namespace std;
//
//bool prime(int n)
//{
//	if(n<=1)	return false;
//	if(n==2 || n==3)	return true;
//	if(n%2==0 || n%3==0)	return false;
//	for(int i=2;i*i<=n;++i)
//	{
//		if(n%i==0)
//			return false;
//	}	
//	return true;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[5000];
//	int j=0;
//	for(int i=1;i<=n;++i)
//	{
//		if(prime(i)) 
//			arr[j++]=i;
//	}
//	int arr2[2500];
//	int l=0;
//	for(int i=0;i<j-1;++i)
//	{
//		if(arr[i+1]-arr[i]==2)
//		{
//			arr2[l++]=arr[i];
//			arr2[l++]=arr[i+1];			
//		}		
//	}
//	for(int i=0;i<l;i+=2)
//	{
//		cout << arr2[i] << " " << arr2[i+1] << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <climits>
//#include <algorithm>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//	int n,m;
//	int arr[20];
//	cin >> n;
//	cin >> m;
//	double max_all = 0.0;
//	while(n--)
//	{
//		int maxn=0,minn=INT_MAX;
//		for(int i=0;i<m;++i)
//		{
//			cin >> arr[i];
//			maxn = max(maxn,arr[i]);
//			minn = min(minn,arr[i]);
//		}
//		int sum =0;
//		for(int i=0;i<m;++i)
//		{
//			sum += arr[i];
//		}
//		double avg = (sum - maxn - minn)*1.0/(m-2); 
//		max_all = max(max_all,avg);
//	}
//	cout << fixed << setprecision(2) << max_all << endl;
//	return 0;
//}


//#include <iostream>
//#include <climits>
//using namespace std;
//
//int max(int a,int b)
//{
//	return	a > b ? a : b;
//}
//int min(int a,int b)
//{
//	return	a < b ? a : b;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    int maxn = 0;
//    int minn = INT_MAX;
//    int each_num = 0;
//    while(n--)
//    {
//        cin >> each_num;
//        maxn = max(each_num,maxn);
//        minn = min(each_num,maxn);
//    }
//    cout << maxn - minn;
//    return 0;
//}

//int max(int a,int b,int c)
//{
//	int max1 = a > b ? a : b;
//	int max = max1 > c ? max1 : c;
//	return	max;
//}
////int max(int a,int b,int c)
////{
////	return	(a > b ? a : b) > c ? (a > b ? a : b) : c;
////}
//
//
//int main() 
//{
//	int a,b,c;
//	cin >> a >> b >> c;
//	double m =max(a,b,c)/(max(a+b,b,c)*max(a,b,b+c));
//	cout << fixed << setprecision(3) << m << endl;
//	return 0;
//}
