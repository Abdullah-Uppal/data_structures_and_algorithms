#include <iostream>

void insertionsort(int arr[], int size);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {78, 45, 3, 42, 21, 34, 5, 66, 9, 10};
    insertionsort(arr, SIZE);
    for (int i = 0; i<SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void insertionsort(int arr[], int size) {
    for (int i = 1; i<size; ++i) {
        int j = i-1;
        int t = arr[i];
        while (j>=0 && arr[j]>t) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = t;
    }
}