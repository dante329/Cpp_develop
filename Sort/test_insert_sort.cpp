#include <iostream>
 
using namespace std;

/// <summary>
/// 直接插入排序
/// </summary>
/// <param name="a">一个数组</param>
/// <param name="b">该数组的大小</param>
void InsertSort(int* a, int n)
{
    for (int i = 0; i <= n - 1; ++i)
    {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestSort()
{
	int n; cin >> n;
	int a[n];
    for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		a[i] = i*i - 10*i + 10;
	}
	PrintArray(a, sizeof(a) / sizeof(int));
    // 使用 InsertSort 或者 ShellSort 进行排序
    InsertSort(a, sizeof(a) / sizeof(int));
//    ShellSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
    TestSort();
    return 0;
}

