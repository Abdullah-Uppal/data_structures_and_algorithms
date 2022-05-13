#include <iostream>

int search(int element, int arr[], int n);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {564, 34, 23, 6, 43, 456, 4, 54, 2, 1};
    int index = search(456, arr, SIZE);
    if (index > -1)
        std::cout << "Element 456 found at: " << index << std::endl;
    else
        std::cout << "Element not found\n";  
    return 0;
}

int search(int element, int arr[], int n) {
    for (int i = 0; i<n; ++i) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}