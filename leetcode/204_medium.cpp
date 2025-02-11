// https://leetcode.com/problems/count-primes/
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <iostream>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;

        std::vector<bool> a(n + 1, true);
        a[0] = a[1] = false;

        for (long p = 2; p < n; p++) {
            if (a[p]) {
                count++;
            }

            for (long s = p * p; s < n; s = s + p) {
                a[s] = false;
            }
        }

        return count;
    }
};

int main() {
    Solution o;
    std::cout << o.countPrimes(100000) << std::endl;
    return 0;
}
