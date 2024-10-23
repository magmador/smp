#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<long long> precomputed_power_of_10;

static void precompute_power_of_10(int capacity) {
    long long power = 1;
    for (int i = 0; i < capacity; i++) {
        precomputed_power_of_10.push_back(power);
        power *= 10;
    }
}

static long long count_digits_in_number(long long num) {
    long long digits_count = 0;
    while(num > 0) {
        num /= 10;
        digits_count++;
    }
    return digits_count;
}

static bool is_kaprekar_number(long long num) {
    long long square = num * num;
    long long digits_count = count_digits_in_number(square);
    long long separate_point = 1;

    for (long long i = 1; i < digits_count; i++) {
        separate_point = precomputed_power_of_10[i];

        if (separate_point == num) {
            return false;
        }

        long long first_part = square / separate_point;
        long long second_part = square % separate_point;

        if (first_part + second_part == num) {
            return true;
        }
    }
    return false;
}

int main() {
    precompute_power_of_10(15); // Assume that 10 ^ 15 is enough for our task. Can do more

    for (long long i = 0; i < 5000000; i++) {
        if (is_kaprekar_number(i))
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
