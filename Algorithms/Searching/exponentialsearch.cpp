#include <iostream>

int exponentialsearch(int element, int arr[], int n);
int binarysearch(int element, int arr[], int start, int end);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 4, 6, 23, 34, 43, 54, 456, 564};
    int tosearch = 456;
    int index = exponentialsearch(tosearch, arr, SIZE);
    if (index > -1)
        std::cout << "Element " << tosearch <<  " found at: " << index << std::endl;
    else
        std::cout << "Element not found\n";  
    return 0;
}

int exponentialsearch(int element, int arr[], int n) {
    if (arr[0] == element) {
        return 0;
    }
    int i = 1;
    while (i<n && arr[i] < element) {
        i *= 2;
    }
    // i divided by 2 because we want to 
    // start search from the index at which 
    // the condition arr[i*2] > element is true 
    return binarysearch(element, 
        arr, i/2, 
        i > n? n: i);
}

int binarysearch(int element, int arr[], int start, int end) {
    if (start>end) {
        return -1;
    }
    int mid = (start+end)/2;
    if (arr[mid] == element) {
        return mid;
    }
    else if (arr[mid] < element) {
        return binarysearch(element, arr, mid+1, end);
    }
    return binarysearch(element, arr, start, mid-1);
}