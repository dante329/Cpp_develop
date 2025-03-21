//要点：第一行的按法是靠枚举从0到五位二进制数所有可能性，从第二行开始按法是要关掉上一行开着的灯，第二行不管上一行，下面再就辐射不到了，最后检查是否完成就看最后一行是不是灯全亮了
#include<iostream>
#include<cstring>

using namespace std;
const int N = 10;
int a[N]; //用来存储每一行的数据，用二进制数表示，取代了用二维数组存储测试用例 
int t[N]; //在枚举按法之后的循环中，不能直接对a[N]进行改变，要用一个临时的数组拷贝a数组 
int n = 5; //题目给出的数据就是5x5的，直接定义一个n 

int calc(int x)
{
	int cnt = 0;
	while(x)
	{
//		x &= (1<<n)-1;
		x &= x-1;
		cnt++;
	}
	return cnt;
}

int main()
{
	int round; cin >> round;
	while(round--)
	{
		//将a数组所有元素初始化为0，第一次进入时全局变量自动会初始化为0，为什么我们还要memset成0呢，因为这是多组测试用例，在下一次进入时要清空之前的数据 
		memset(a,0,sizeof(a)); 
		//测试用例存到a[0]~a[4]中 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) //注意这里，假设某一行从左往右第一个就遇到0时，此时j=0，a[i]=0。那么a[i] |= 1 << j;相当于是在a[i]的最右边将0变成了1，所以注意这样实际上存下来的数字与测试用例0变1，1变0之后的数列仍然是反过来的，数列的最左边是最低位，右边是高位 
			{
				char ch; cin >> ch;
	//			if(ch == '1') a[i] |= 1;
				//反着存，开灯为0，关灯为1，下面就要将所有的1变成0
				if(ch == '0') a[i] |= 1 << j; 
			}
		}
		//定义一个无限大，等会要与cnt取最小 
		int ret = 0x3f3f3f3f;
		//枚举第一行中所有的按法
		for(int i=0;i<(1<<n);i++) 
		{
			int cnt = 0;
			memcpy(t,a,sizeof(a)); 
			int push = i; //第一次进入循环就是第一行的按法，到第二行时按法会根据第一行作调整，所以要搞个对于for循环的全局变量存起来 
			for(int j=0;j<n;j++) //对于每一种第一行的按法，其他行对应的按法都是固定的
			{	
				//根据按法的数字的二进制位中的1确定关灯的次数
				cnt += calc(push);
				//当前行的状态（第一行的push是随机的，后面的都是有逻辑的，都是为了关掉上一行的灯（我们是反着储存的，所以开灯问题变成了关灯问题）） 
				t[j] = t[j] ^ push ^ (push << 1) ^ (push >> 1);
				//注意上面的^(push << 1)操作可能会让最高位的下一位变成1，所以要消除这个1
				t[j] &= (1 << n) - 1; 
				//下一行的状态（受上一行影响） 
				t[j+1] ^= push;
				//根据当前行未关掉的灯确定下一行的push
				push = t[j]; 
			}
			//continue写的多余 
//			if(t[n-1] != 0) continue;
//			else ret = min(ret,cnt);
			if(t[n-1] == 0) ret = min(ret,cnt);
		}
		if(ret <= 6) cout << ret << endl;
		else cout << -1 << endl; 
	}
	
	return 0;	
} 
