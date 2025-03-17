#include <iostream>
using namespace std;
 
//定义方向向量
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
const int N = 10;
int arr[N][N]; 
int main() 
{
	int x = 1, y = 1;
	int n; cin >> n;
	int cnt = 1;
	int t = 0; //t表示方向向量的下标，从0开始 
	while(cnt <= n*n)
	{
		
		arr[x][y] = cnt++;
		//计算下一个位置 
		int a = x + dx[t],b = y + dy[t];
		//判断是否越界 
		if(a > n || b > n || a < 1 || b < 1 || arr[a][b])
		{
			t = (t + 1)%4;		
			a = x + dx[t],b = y + dy[t];
		}	
		x = a, y = b;	
	}
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			printf("%3d",arr[i][j]);
		}
		puts("");
	} 
	return 0;
}

//四个while的解法
//#include <iostream>
//using namespace std;
//
//struct Pos {
//    int x, y;
//};
//
//int main() {
//    int n;
//    cout << "Enter the size of the matrix (n x n): ";
//    cin >> n;
//
//    if (n <= 0) {
//        cout << "Invalid input! Size must be a positive integer." << endl;
//        return 1;
//    }
//
//    int a[n][n]; // 从 0 开始
//    Pos pos = {0, 0}; // 初始位置
//    int count = 1; // 填充的数字
//    int bottom = 0, high = n - 1; // 边界
//
//    while (count <= n * n) {
//        // 从左到右填充上边界
//        while (pos.y <= high && count <= n * n) {
//            a[pos.x][pos.y++] = count++;
//        }
//        pos.x++; // 向下移动一行
//        pos.y--; // 修正 y 的值
//
//        // 从上到下填充右边界
//        while (pos.x <= high && count <= n * n) {
//            a[pos.x++][pos.y] = count++;
//        }
//        pos.y--; // 向左移动一列
//        pos.x--; // 修正 x 的值
//
//        // 从右到左填充下边界
//        while (pos.y >= bottom && count <= n * n) {
//            a[pos.x][pos.y--] = count++;
//        }
//        pos.x--; // 向上移动一行
//        pos.y++; // 修正 y 的值
//
//        // 从下到上填充左边界
//        while (pos.x > bottom && count <= n * n) {
//            a[pos.x--][pos.y] = count++;
//        }
//        pos.y++; // 向右移动一列
//        pos.x++; // 修正 x 的值
//
//        // 缩小边界
//        bottom++;
//        high--;
//    }
//
//    // 输出矩阵
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << a[i][j] << "\t";
//        }
//        cout << endl;
//    }
//
//    return 0;
//} 
