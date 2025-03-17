#include <iostream>
using namespace std;
 
//���巽������
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
const int N = 10;
int arr[N][N]; 
int main() 
{
	int x = 1, y = 1;
	int n; cin >> n;
	int cnt = 1;
	int t = 0; //t��ʾ�����������±꣬��0��ʼ 
	while(cnt <= n*n)
	{
		
		arr[x][y] = cnt++;
		//������һ��λ�� 
		int a = x + dx[t],b = y + dy[t];
		//�ж��Ƿ�Խ�� 
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

//�ĸ�while�Ľⷨ
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
//    int a[n][n]; // �� 0 ��ʼ
//    Pos pos = {0, 0}; // ��ʼλ��
//    int count = 1; // ��������
//    int bottom = 0, high = n - 1; // �߽�
//
//    while (count <= n * n) {
//        // ����������ϱ߽�
//        while (pos.y <= high && count <= n * n) {
//            a[pos.x][pos.y++] = count++;
//        }
//        pos.x++; // �����ƶ�һ��
//        pos.y--; // ���� y ��ֵ
//
//        // ���ϵ�������ұ߽�
//        while (pos.x <= high && count <= n * n) {
//            a[pos.x++][pos.y] = count++;
//        }
//        pos.y--; // �����ƶ�һ��
//        pos.x--; // ���� x ��ֵ
//
//        // ���ҵ�������±߽�
//        while (pos.y >= bottom && count <= n * n) {
//            a[pos.x][pos.y--] = count++;
//        }
//        pos.x--; // �����ƶ�һ��
//        pos.y++; // ���� y ��ֵ
//
//        // ���µ��������߽�
//        while (pos.x > bottom && count <= n * n) {
//            a[pos.x--][pos.y] = count++;
//        }
//        pos.y++; // �����ƶ�һ��
//        pos.x++; // ���� x ��ֵ
//
//        // ��С�߽�
//        bottom++;
//        high--;
//    }
//
//    // �������
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << a[i][j] << "\t";
//        }
//        cout << endl;
//    }
//
//    return 0;
//} 
