#include <iostream>
#include <vector>

#define MAX(a, b) ( (a) > (b) ? (a): (b) )
int zerooneknapsack(int capacity, std::vector<int> weights, std::vector<int> values);

int main() {
    std::vector<int> weights {30, 25, 75, 15, 35};
    std::vector<int> values {35, 30, 70, 25, 30};
    std::cout << zerooneknapsack(60, weights, values) << "\n";
}

int zerooneknapsack(int capacity, std::vector<int> weights, std::vector<int> values) {
    //Assuming weights and values are equal in size
    int n = weights.size();
    std::vector<std::vector<int>> s(n+1, std::vector<int>(capacity+1, 0));
    for (int i = 1; i<=capacity; ++i) {
        for (int j = 1; j<=n; ++j) {
            s[j][i] = s[j-1][i];
            if (weights[j-1] <= i) {
                s[j][i] = MAX(
                    ( s[j][i] ),
                    (s[j-1][i-weights[j-1]] + values[j-1])
                );
            }
        }
    }
    return s[n][capacity];
}