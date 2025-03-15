#include <iostream>
#include <algorithm>

// 快速排序的左右指针法实现
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;  // 递归终止条件：子数组长度为 0 或 1

    // 选择基准值（这里选择数组的第一个元素）
    int pivot = arr[left];

    // 初始化左右指针
    int i = left, j = right;

    // 划分过程
    while (i < j) {
        // 从右向左找第一个小于基准值的元素
        while (i < j && arr[j] >= pivot) j--;
        // 从左向右找第一个大于基准值的元素
        while (i < j && arr[i] <= pivot) i++;
        // 交换这两个元素
        if (i < j) std::swap(arr[i], arr[j]);
    }

    // 将基准值放到正确的位置（i 和 j 相遇的位置）
    std::swap(arr[left], arr[i]);

    // 递归处理左半部分（小于基准值的部分）
    quickSort(arr, left, i - 1);

    // 递归处理右半部分（大于基准值的部分）
    quickSort(arr, i + 1, right);
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 测试代码
int main() {
    // 测试用例 1
    int arr1[] = {3, 6, 8, 10, 1, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, n1);
    quickSort(arr1, 0, n1 - 1);
    std::cout << "Sorted array 1: ";
    printArray(arr1, n1);

    // 测试用例 2
    int arr2[] = {9, 4, 2, 7, 5, 10, 1, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array 2: ";
    printArray(arr2, n2);
    quickSort(arr2, 0, n2 - 1);
    std::cout << "Sorted array 2: ";
    printArray(arr2, n2);

    // 测试用例 3（包含重复元素）
    int arr3[] = {5, 3, 8, 3, 2, 5, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array 3: ";
    printArray(arr3, n3);
    quickSort(arr3, 0, n3 - 1);
    std::cout << "Sorted array 3: ";
    printArray(arr3, n3);

    return 0;
}
