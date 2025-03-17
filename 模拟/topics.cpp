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

    int a[n][n]; // �� 0 ��ʼ
    Pos pos = {0, 0}; // ��ʼλ��
    int count = 1; // ��������
    int bottom = 0, high = n - 1; // �߽�

    while (count <= n * n) {
        // ����������ϱ߽�
        while (pos.y <= high && count <= n * n) {
            a[pos.x][pos.y++] = count++;
        }
        pos.x++; // �����ƶ�һ��
        pos.y--; // ���� y ��ֵ

        // ���ϵ�������ұ߽�
        while (pos.x <= high && count <= n * n) {
            a[pos.x++][pos.y] = count++;
        }
        pos.y--; // �����ƶ�һ��
        pos.x--; // ���� x ��ֵ

        // ���ҵ�������±߽�
        while (pos.y >= bottom && count <= n * n) {
            a[pos.x][pos.y--] = count++;
        }
        pos.x--; // �����ƶ�һ��
        pos.y++; // ���� y ��ֵ

        // ���µ��������߽�
        while (pos.x > bottom && count <= n * n) {
            a[pos.x--][pos.y] = count++;
        }
        pos.y++; // �����ƶ�һ��
        pos.x++; // ���� x ��ֵ

        // ��С�߽�
        bottom++;
        high--;
    }

    // �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
