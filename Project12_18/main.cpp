#include <iostream>
#include <iomanip>
using namespace std;

//int main()
//{
//	float a = 1.5;
//	int b = 50, c = 450, d = 2300;
//	printf("%-5d\n%-5d\n%-5d\n%-5.2f\n",b,c,d,a);
//	return 0;
//}

//int main()
//{
//	char s[10] = {0};
//	scanf("%9s",s);
//	printf("%s",s);
//	return 0;
//}

//int main()
//{
//	int a = 9;
//	cout << oct << a << endl;
//	return 0;
//}

#include <iostream>
#include <iomanip>
using namespace std;
//int main()
//{
//    float r;
//    float pi = 3.14159f;
//    cin >> r;
//    float L = 2.0*r;
//    float C = 2*pi*r;
//    float S = pi*r*r;
//    cout << fixed << setprecision(4) << L ;
//    return 0;
//}

//int main()
//{
//    float pi = 3.14159f;
//    cout << pi ;
//    return 0;
//}

int main() {
    double pi = 3.14159265358979;
    cout << setprecision(4) << pi << endl;  // 保留4位有效数字
    cout << fixed << setprecision(4) << pi << endl;  // 保留4位小数
    return 0;
}
