#include <iostream>
#include <map>

unsigned long long factorial(int n);

int main() {
    std::cout << factorial(15) << std::endl;
    return 0;
}

std::map<int, unsigned long long> cache;
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    return (cache[n] = n*factorial(n-1));
}