#include <iostream>
#include <algorithm>

// �������������ָ�뷨ʵ��
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;  // �ݹ���ֹ�����������鳤��Ϊ 0 �� 1

    // ѡ���׼ֵ������ѡ������ĵ�һ��Ԫ�أ�
    int pivot = arr[left];

    // ��ʼ������ָ��
    int i = left, j = right;

    // ���ֹ���
    while (i < j) {
        // ���������ҵ�һ��С�ڻ�׼ֵ��Ԫ��
        while (i < j && arr[j] >= pivot) j--;
        // ���������ҵ�һ�����ڻ�׼ֵ��Ԫ��
        while (i < j && arr[i] <= pivot) i++;
        // ����������Ԫ��
        if (i < j) std::swap(arr[i], arr[j]);
    }

    // ����׼ֵ�ŵ���ȷ��λ�ã�i �� j ������λ�ã�
    std::swap(arr[left], arr[i]);

    // �ݹ鴦����벿�֣�С�ڻ�׼ֵ�Ĳ��֣�
    quickSort(arr, left, i - 1);

    // �ݹ鴦���Ұ벿�֣����ڻ�׼ֵ�Ĳ��֣�
    quickSort(arr, i + 1, right);
}

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ���Դ���
int main() {
    // �������� 1
    int arr1[] = {3, 6, 8, 10, 1, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, n1);
    quickSort(arr1, 0, n1 - 1);
    std::cout << "Sorted array 1: ";
    printArray(arr1, n1);

    // �������� 2
    int arr2[] = {9, 4, 2, 7, 5, 10, 1, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array 2: ";
    printArray(arr2, n2);
    quickSort(arr2, 0, n2 - 1);
    std::cout << "Sorted array 2: ";
    printArray(arr2, n2);

    // �������� 3�������ظ�Ԫ�أ�
    int arr3[] = {5, 3, 8, 3, 2, 5, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array 3: ";
    printArray(arr3, n3);
    quickSort(arr3, 0, n3 - 1);
    std::cout << "Sorted array 3: ";
    printArray(arr3, n3);

    return 0;
}
