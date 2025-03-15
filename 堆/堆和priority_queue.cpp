//默认建大根堆 
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n,heap[N]; //n用来记录heap存放的有效元素个数，heap用来存储堆的数据，父子关系是靠公式计算得来（堆是完全二叉树） 

//向上调整 （就是子节点要跟父节点换，一个子节点的父节点只有一个，所以直接交换即可） 
void up(int child) //传入要调整的节点的下标（下标具有唯一性，堆中允许节点的值相同） 
{
	int parent = child / 2;
	while(parent >= 1 && heap[child] > heap[parent]) // 这里必须是parent >= 1 ，不能是parent > 1 。 parent > 1时，如果该节点是最大的，那么只能被调整到堆顶的子节点的位置。
	{
		swap(heap[child],heap[parent]);
		//杯换掉的那个元素就不管了，它已经在正确的位置上了，现在我们要更新child节点 ，然后再由公式得出parent节点 
		child = parent;
		parent = child / 2;
	}
}

//向下调整 （父节点要跟子节点换，一个父节点最多有两个子节点，所以我们要找出最大的那个子节点作比较） 
//void down(int parent)
//{
//	int child = parent * 2; //先默认指向左节点
//	if(heap[child] < heap[child + 1]) child++;
//	while(parent < n && heap[parent] < heap[child]) //parent < n的判断完全没有必要，child比parent大，判断child即可 
//	{
//		swap(heap[parent],heap[child]);
//		parent = child;
//		child = parent / 2;	
//	} 
//}

//void down(int parent)
//{
//	int child = parent * 2; //先默认指向左节点 思考：child是两倍的parent得到的，这个时候有没有可能超出了n呢？所以要先判断child是否存在 
//	while(child <= n) //孩子存在才有下文   //child <= n和下面if中的child + 1 <=n可以合并成 child < n
//	{
//		if(child + 1 <=n && heap[child] < heap[child + 1]) child++;
//		while(heap[parent] < heap[child]) //这里还用while岂不是死循环了，要用这个条件作为跳出循环的跳板，所以要用if判断 
//		{
//			parent = child;
//			child = parent / 2; //漏洞太多 
//		}
//	}
//}

//void down(int parent)
//{
//	int child = parent * 2; //先默认指向左节点 思考：child是两倍的parent得到的，这个时候有没有可能超出了n呢？所以要先判断child是否存在 
//	while(child <= n) //孩子存在才有下文   //child <= n和下面if中的child + 1 <=n可以合并成 child < n
//	{
//		if(child + 1 <=n && heap[child] < heap[child + 1]) child++;
//		if(heap[parent] >= heap[child]) return; //>=
//		swap(heap[parent],heap[child]);
//		parent = child;
//		child = parent * 2;
//		
//	}
//}

void down(int parent)
{
	int child = parent * 2; //先默认指向左节点 思考：child是两倍的parent得到的，这个时候有没有可能超出了n呢？所以要先判断child是否存在 
	while(child < n) //孩子存在才有下文   //child <= n和下面if中的child + 1 <=n可以合并成 child < n
	{
		if(heap[child] < heap[child + 1]) child++;
		if(heap[parent] >= heap[child]) return; //heap[parent] >= heap[child]比heap[parent] > heap[child]少走一步，但都是正确的
		swap(heap[parent],heap[child]);
		parent = child;
		child = parent * 2;
		
	}
}

void push(int x)
{
	heap[++n] = x; //最刚开始n=0，存入第一个元素的时候++n，是在1的位置存入，0的位置没有任何元素 
	up(n);
}

void pop()
{
	swap(heap[1],heap[n]);
	n--;
	down(1);
}

int size()
{
	return n;
}

int top() //这个top实际上是有bug的，就是在没有元素的时候是不能调用这个接口的，这样的条件检查我们不在函数内实现，而是在调用前进行检查 
{
	return heap[1];
}

int main() 
{
	int a[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0};
	
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		push(a[i]);
	}
	
	while(size())
	{
		cout << top() << " ";
		pop();
	}
	
	
	return 0;
}
