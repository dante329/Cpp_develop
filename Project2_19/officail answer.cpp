#include <iostream>
#include <vector>
using namespace std;
const int N = 30;
typedef pair<int, int> PII;
int n;
vector<int> p[N]; // ���� n ����?��Ĳ�
PII find(int x)
{
 for(int i = 0; i < n; i++)
 {
 for(int j = 0; j < p[i].size(); j++)
 {
 if(p[i][j] == x)
 {
 return {i, j};
 }
 }
 }
}
void clean(int x, int y)
{
 // �� [x, y] ���ϵ�?���λ
 for(int j = y + 1; j < p[x].size(); j++)
 {
 int t = p[x][j];
 p[t].push_back(t);
 }
 p[x].resize(y + 1);
}
void move(int x1, int y1, int x2)
{
 // �� [x1, y1] �������ϵ�?����� x2 ��?
 for(int j = y1; j < p[x1].size(); j++)
 {
 p[x2].push_back(p[x1][j]);
 }
 p[x1].resize(y1);
}
int main()
{
 cin >> n;
 // ��ʼ��
 for(int i = 0; i < n; i++)
 {
 p[i].push_back(i);
 }
 string op1, op2;
 int a, b;
 while(cin >> op1 >> a >> op2 >> b)
 {
 // ���� a �� b ��λ��
 PII pa = find(a);
 int x1 = pa.first, y1 = pa.second;
 PII pb = find(b);
 int x2 = pb.first, y2 = pb.second;
 if(x1 == x2) continue; // �����Ϸ��Ĳ���
 if(op1 == "move") // �� a ��?��λ
 {
 clean(x1, y1);
 }
 if(op2 == "onto") // �� b ��?��λ
 {
 clean(x2, y2);
 }
 move(x1, y1, x2);
 }
 // ��ӡ
 for(int i = 0; i < n; i++)
 {
 cout << i << ":";
 for(int j = 0; j < p[i].size(); j++)
 {
 cout << " " << p[i][j];
 }
 cout << endl;
 }
 return 0;
}
 	
