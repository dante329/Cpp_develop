#include <iostream>
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int a[N];
int tmp[N];
int n;

LL merge(int left,int right)
{
	if(left >= right) return 0;
	
	int mid = (left + right) / 2;
	LL ret = 0;
	//实际上计算左、右区间逆序对个数等价于 当左右区间长度为1时的计算跨区间区间逆序对个数 
	ret += merge(left,mid); //计算左区间逆序对个数 
	ret += merge(mid+1,right);  //计算右区间逆序对个数 
	//计算跨区间区间逆序对个数 
	int cur1 = left,cur2 = mid+1,i = left;
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] > a[cur2])
		{
			ret += mid - cur1 + 1;			
			tmp[i++] = a[cur2++];
		}
		else 
		{
			tmp[i++] = a[cur1++];
		}
	}
	//以下注释是错误思路 
//	while(cur1 <= mid && cur2 <= right)
//	{
//		while(a[cur1] > a[cur2] && cur2 <= right) tmp[i++] = a[cur2++];
//		ret += cur2 - (mid + 1);	 
//		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
//	}
	while(cur1 <= mid) tmp[i++] = a[cur1++];
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	for(int j=left;j<=right;j++) a[j] = tmp[j];
	
	return ret;
}

int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cout << merge(1,n) << endl;	
	return 0;
}

//代码能够计算左半内部和右半内部逆序对的秘密，隐藏在 递归调用的返回值累加机制 中。
//用 "公司汇报" 比喻理解递归
//假设你是一家公司的CEO，要统计全国所有分公司的逆序对总数。你采用以下策略：
//分解任务：将全国划分为东部和西部两个大区
//委托统计：
//东部大区经理调用 merge(东部)，返回东部内部的逆序对数
//西部大区经理调用 merge(西部)，返回西部内部的逆序对数
//跨区统计：你亲自计算东部与西部之间的跨区逆序对
//汇总结果：总逆序对 = 东部内部 + 西部内部 + 跨区
//这里的精妙之处在于：当东部大区经理汇报时，他的结果已经包含了东部内部所有子分公司的逆序对（包括子分公司的内部和跨子分公司）。递归的层级结构自动完成了逐级汇总。
//
//递归的树形结构保证全覆盖
//        [总任务]
//       /        \
//  [左半任务]  [右半任务]
//    /  \        /  \
//  ...  ...    ...  ...  // 直到原子任务
//每个非叶子节点负责：
//汇总子节点的结果（左右内部）
//计算跨子节点的逆序对（合并时）
//叶子节点（单个元素）贡献0
