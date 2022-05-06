#include <iostream>

void selectionsort(int arr[], int size);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {9, 5, 3, 23, 5, 7, 34, 23, 1, 10}; 
    selectionsort(arr, SIZE);
    for (int i = 0; i<SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void selectionsort(int arr[], int size) {
    for (int i = 0; i<size-1; ++i) {
        int min = i;
        for (int j = i+1; j<size; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }   
}