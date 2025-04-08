#include <iostream>
using namespace std;
int k, x, y;
void dfs(int a, int b, int len, int x, int y)
{
 if(len == 1) return;
 len /= 2;
 if(x < a + len && y < b + len) // �ϰ���������
 {
 cout << a + len << " " << b + len << " " << 1 << endl;
 dfs(a, b, len, x, y);
 dfs(a, b + len, len, a + len - 1, b + len);
 dfs(a + len, b, len, a + len, b + len - 1);
 dfs(a + len, b + len, len, a + len, b + len);
 }
 else if(x >= a + len && y >= b + len) // �ϰ���������
 {
 cout << a + len - 1 << " " << b + len - 1 << " " << 4 << endl;
 dfs(a, b, len, a + len - 1, b + len - 1);
 dfs(a, b + len, len, a + len - 1, b + len);
 dfs(a + len, b, len, a + len, b + len - 1);
 dfs(a + len, b + len, len, x, y);
 }
 else if(x >= a + len) // �ϰ���������
 {
 cout << a + len - 1 << " " << b + len << " " << 3 << endl;
 dfs(a, b, len, a + len - 1, b + len - 1);
 dfs(a, b + len, len, a + len - 1, b + len);
 dfs(a + len, b, len, x, y);
 dfs(a + len, b + len, len, a + len, b + len);
 }
 else // �ϰ���������
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
