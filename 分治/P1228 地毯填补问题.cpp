#include <iostream>
using namespace std;
int k, x, y;
void dfs(int a, int b, int len, int x, int y)
{
 if(len == 1) return;
 len /= 2;
 if(x < a + len && y < b + len) // 障碍物在左上
 {
 cout << a + len << " " << b + len << " " << 1 << endl;
 dfs(a, b, len, x, y);
 dfs(a, b + len, len, a + len - 1, b + len);
 dfs(a + len, b, len, a + len, b + len - 1);
 dfs(a + len, b + len, len, a + len, b + len);
 }
 else if(x >= a + len && y >= b + len) // 障碍物在右下
 {
 cout << a + len - 1 << " " << b + len - 1 << " " << 4 << endl;
 dfs(a, b, len, a + len - 1, b + len - 1);
 dfs(a, b + len, len, a + len - 1, b + len);
 dfs(a + len, b, len, a + len, b + len - 1);
 dfs(a + len, b + len, len, x, y);
 }
 else if(x >= a + len) // 障碍物在左下
 {
 cout << a + len - 1 << " " << b + len << " " << 3 << endl;
 dfs(a, b, len, a + len - 1, b + len - 1);
 dfs(a, b + len, len, a + len - 1, b + len);
 dfs(a + len, b, len, x, y);
 dfs(a + len, b + len, len, a + len, b + len);
 }
 else // 障碍物在右上
 {
 cout << a + len << " " << b + len - 1 << " " << 2 << endl;
 dfs(a, b, len, a + len - 1, b + len - 1);
 dfs(a, b + len, len, x, y);
 dfs(a + len, b, len, a + len, b + len - 1);
 dfs(a + len, b + len, len, a + len, b + len);
 }
}
int main()
{
 cin >> k >> x >> y;
 k = (1 << k);
 dfs(1, 1, k, x, y);
 return 0;
}
