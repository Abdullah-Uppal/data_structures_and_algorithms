#include <iostream>

int binarysearch(int element, int arr[], int n);
int recursivebinarysearch(int element, int arr[], int start, int end);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 4, 6, 23, 34, 43, 54, 456, 564};
    int tosearch = 1;
    int index = recursivebinarysearch(tosearch, arr, 0, SIZE-1);
    std::cout << "(recursive) ";
    if (index > -1)
        std::cout << "Element " << tosearch <<  " found at: " << index << std::endl;
    else
        std::cout << "Element not found\n";  

    tosearch = 54;
    index = binarysearch(tosearch, arr, SIZE);
    std::cout << "(iterative) ";
    if (index > -1)
        std::cout << "Element " << tosearch <<  " found at: " << index << std::endl;
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

int recursivebinarysearch(int element, int arr[], int start, int end) {
    if (start>end) {
        return -1;
    }
    int mid = (start+end)/2;
    if (arr[mid] == element) {
        return mid;
    }
    else if (arr[mid] < element) {
        return recursivebinarysearch(element, arr, mid+1, end);
    }
    return recursivebinarysearch(element, arr, start, mid-1);
}