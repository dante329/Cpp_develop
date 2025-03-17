//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//struct vec{
//	int x,y;
//}vec;
//
//int main()
//{
//	vec.x = 1,vec.y = 1;
//	int n; cin >> n;
//	int a[n+1][n+1];
//	int count = 1;
//	int bottom = 1;
//	int high = n;
//	while(count <= n*n)
//	{
//		while(vec.y <= high && count <= n*n)
//		{
//			a[vec.x][vec.y++] = count++;		
//		}
//		while(vec.x <= high && count <= n*n)
//		{
//			a[vec.x++][vec.y] = count++;
//		}
//		while(vec.y >= bottom && count <= n*n)
//		{
//			a[vec.x][vec.y--] = count++;
//		} 
//		while(vec.x > bottom && count <= n*n)
//		{
//			a[vec.x--][vec.y] = count++;
//		}
//		high--;
//		bottom++;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


#include <iostream>
using namespace std;

struct Pos {
    int x, y;
};

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input! Size must be a positive integer." << endl;
        return 1;
    }

    int a[n][n]; // 从 0 开始
    Pos pos = {0, 0}; // 初始位置
    int count = 1; // 填充的数字
    int bottom = 0, high = n - 1; // 边界

    while (count <= n * n) {
        // 从左到右填充上边界
        while (pos.y <= high && count <= n * n) {
            a[pos.x][pos.y++] = count++;
        }
        pos.x++; // 向下移动一行
        pos.y--; // 修正 y 的值

        // 从上到下填充右边界
        while (pos.x <= high && count <= n * n) {
            a[pos.x++][pos.y] = count++;
        }
        pos.y--; // 向左移动一列
        pos.x--; // 修正 x 的值

        // 从右到左填充下边界
        while (pos.y >= bottom && count <= n * n) {
            a[pos.x][pos.y--] = count++;
        }
        pos.x--; // 向上移动一行
        pos.y++; // 修正 y 的值

        // 从下到上填充左边界
        while (pos.x > bottom && count <= n * n) {
            a[pos.x--][pos.y] = count++;
        }
        pos.y++; // 向右移动一列
        pos.x++; // 修正 x 的值

        // 缩小边界
        bottom++;
        high--;
    }

    // 输出矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
