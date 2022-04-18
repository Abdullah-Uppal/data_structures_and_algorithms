#include <iostream>
#include <vector>

#define MAX(a, b) ( (a) > (b) ? (a): (b) )


// Length of longest common sub-sequence
int len_lcs(std::string x, std::string y);

int main() {
    std::string s = "ABCDEFGHL";
    std::string p = "ABDULLAH";
    std::cout << len_lcs(s, p);   
}

int len_lcs(std::string x, std::string y) {
    int len_x = x.length();
    int len_y = y.length();
    // Create matrix for cache
    int **matrix = new int*[len_x];
    for (int i = 0; i<len_x; i++) {
        matrix[i] = new int[len_y];
    }



    /*
        THE ALGO
    */
    // O(mn)
    for (int i = 0; i<len_x; i++) {
        for (int j = 0; j<len_y; j++) {
            if (x[i] == y[j]) {
                // length of subsequence before 0th index
                // should be 0
                matrix[i][j] = 1 + (i-1<0 ? 0: matrix[i-1][j-1]);
            }
            else {
                matrix[i][j] = MAX(
                    (i-1<0 ? 0: matrix[i-1][j]),
                    (j-1<0 ? 0: matrix[i][j-1])
                );
            }
        }
    }
    int result = matrix[len_x-1][len_y-1];
    // Deleting the matrix
    for (int i = 0; i<len_x; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return result;
}