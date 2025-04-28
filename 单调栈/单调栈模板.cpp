#include <iostream>
#include <stack>
using namespace std;
const int N = 20;
int a[N];
int ret[N];
int n;

//在左边找 就要从左到右遍历；在右边找 就要从右到左遍历 
//为什么找大的就会创建一个单调递减的栈，因为如果遇到的数越来越大，那么这个数一定要放入栈顶作为备选没有问题吧？又大又近，两个都最优（贪心思想）；但是如果遇到的是一个比当前栈顶元素小的数字，那么这个数字也是可能成为结果的，因为虽然它的数值没有之前的栈顶元素大，但是它离下一个元素更近。难点就是理解这"大"和"近"两个指标 

//模板1：找到当前元素 左边 离它最近的 比它大的 元素在哪（储存下标） 
void test1()
{
	stack<int> st; //单调栈 存下标 
	
	for(int i=1;i<=n;i++) //从左往右遍历元素
	{
//		if(st.empty()) ret[i] = 0; //这句话写的多余，当st里面没有元素时会跳过所有语句，然后执行下一次循环，原本里面就是0不用管 
		//遇到比栈顶元素更大更近的就要把旧的栈顶元素删掉，然后放入当前这个（入栈操作在下面统一执行） 
		while(st.size() && a[i] >= a[st.top()]) st.pop(); 
		
		//当前的a[i]小于栈顶元素，就为a[i]找到了离它最近的比它大的元素，更新结果 
		if(st.size()) ret[i] = st.top();
		
		st.push(i); 
	}
}

//模板2：找到当前元素 左边 离它最近的 比它小的 元素在哪（储存下标） 
void test2()
{
	stack<int> st;
	
	for(int i=1;i<=n;i++) //从左往右遍历元素
	{
		//我要找比它小的，我遇到比栈顶元素小的就一定要把原来的删除，把小的更新上去 
		while(st.size() && a[i] <= a[st.top()]) st.pop();
		
		//当栈顶元素比当前的a[i]小的时候，这就是结果 
		if(st.size()) ret[i] = st.top();
	
		st.push(i);
	}
}

//模板3：找到当前元素 右边 离它最近的 比它大的 元素在哪（储存下标） 
void test3()
{
	stack<int> st; //单调栈 存下标 
	
	for(int i=n;i>=1;i--) //从右往左遍历元素
	{
		while(st.size() && a[i] >= a[st.top()]) st.pop(); 
		
		if(st.size()) ret[i] = st.top();
		
		st.push(i); 
	}
}

//模板4：找到当前元素 右边 离它最近的 比它小的 元素在哪（储存下标） 
void test4()
{
	stack<int> st;
	
	for(int i=n;i>=1;i--) //从右往左遍历元素
	{
		while(st.size() && a[i] <= a[st.top()]) st.pop();
		
		if(st.size()) ret[i] = st.top();
	
		st.push(i);
	}
}

int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	test4();
	
	for(int i=1;i<=n;i++) cout << ret[i] << " ";
	
	return 0;
}
