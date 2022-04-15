#include <iostream>
#include <vector>

#define MAX(a, b) ( (a) > (b) ? (a): (b) )

int unbounded_knapsack(int capacity, std::vector<int> weights, std::vector<int> values);

int main() {
    std::vector<int> weights {10, 20, 30};
    std::vector<int> values {60, 100, 120};
    std::cout << unbounded_knapsack(50, weights, values) << "\n";
}

int unbounded_knapsack(int capacity, std::vector<int> weights, std::vector<int> values) {
    //Assuming weights and values are equal in size
    int n = weights.size();
    std::vector<int> s(capacity+1);
    s[0]=0;
    for (int i = 1; i<=capacity; ++i) {
        s[i] = 0;
        for (int j = 0; j<n; ++j) {
            if (weights[j] <= i) {
                s[i] = MAX(s[i], s[i-weights[j]]+values[j]);
            }
        }
    }
    return s[capacity];
}