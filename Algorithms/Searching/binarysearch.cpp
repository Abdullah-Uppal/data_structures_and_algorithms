#include <iostream>

int binarysearch(int element, int arr[], int n);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 4, 6, 23, 34, 43, 54, 456, 564};
    int index = binarysearch(456, arr, SIZE);
    if (index > -1)
        std::cout << "Element 456 found at: " << index << std::endl;
    else
        std::cout << "Element not found\n";  
    return 0;
}

int binarysearch(int element, int arr[], int n) {
    int start = 0;
    int end = n-1;
    while (start<=end) {
        int mid = (end+start)/2;
        if (arr[mid] == element) {
            return mid;
        }
        else if (arr[mid]<element) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }    
    return -1;
}