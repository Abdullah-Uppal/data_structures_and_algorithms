#include <iostream>

void merge(int arr[], int start, int mid, int end);
void mergesort(int arr[], int start, int end);
int main() {
    const int SIZE = 10;
    int arr[SIZE] = {78, 45, 3, 42, 21, 34, 5, 66, 9, 10};
    mergesort(arr, 0, SIZE-1);
    for (int i = 0; i<SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
void merge(int arr[], int start, int mid, int end) {
    int* temp = new int[end-start+1];
    int i = start;
    int j = mid+1;
    int k = 0;
    while (i<=mid && j<=end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            ++i;
        }
        else {
            temp[k] = arr[j];
            ++j;
        }
        ++k;
    }
    while (i<=mid) {
        temp[k] = arr[i];
        ++i;
        ++k;
    }
    while (j<=end) {
        temp[k] = arr[j];
        ++j;
        ++k;
    }
    // Copy back the array.
    i = start;
    for (k = 0; k<end-start+1; ++k) {
        arr[i] = temp[k];
        ++i;
    }
    delete temp;
}
void mergesort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int m = (start+end)/2;
    mergesort(arr, start, m);
    mergesort(arr, m+1, end);
    merge(arr, start, m, end);
}