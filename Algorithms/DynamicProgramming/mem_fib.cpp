#include <iostream>
#include <map>

unsigned long fib(int n);

int main() {
    std::cout << fib(200) << std::endl;
    return 0;
}

std::map<int, unsigned long> cache;
unsigned long fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    cache[n] = fib(n-1) + fib(n-2); 
    return cache[n];
}