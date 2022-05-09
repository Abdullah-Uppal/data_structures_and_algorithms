#include <iostream>
#include <limits>
#include <cstring>

void countingsort(int arr[], int size);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {78, 45, 3, 42, 21, 34, 5, 66, 9, 10};
    countingsort(arr, SIZE);
    for (int i = 0; i<SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void countingsort(int arr[], int size) {
    // Find max numbers
    int max = INT_MIN;
    for (int i = 0; i<size; ++i) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    int* count_array = new int[max+1];
    memset(count_array, 0, sizeof(int)*(max+1));
    for (int i = 0; i<size; ++i) {
        count_array[arr[i]] += 1;
    }
    for (int i = 0, j=0; i<max+1; ++i) {
        if (count_array[i]>0) {
            while(count_array[i]>0) {
                arr[j] = i;
                count_array[i]--;
                j++;
            }
        }
    }
    delete count_array;
}