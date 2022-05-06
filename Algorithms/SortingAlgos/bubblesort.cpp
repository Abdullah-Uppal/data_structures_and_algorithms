#include <iostream>
#include <vector>

void bubblesort(int arr[], int size);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {9, 5, 3, 23, 5, 7, 34, 23, 1, 10}; 
    bubblesort(arr, SIZE);
    for (int i = 0; i<SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void bubblesort(int arr[], int size) {
    for (int i = 0; i<size; ++i) {
        for (int j = i+1; j<size; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }   
}