#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int reverse(int x);

int main() {

    int num1 = 1534236469;
    int reversed_num = reverse(num1);
    
    cout << "Reverse of 123 is: " << reversed_num;

    return 0;
}

int reverse(int x) {
    if (x == 0) return x;

    vector<int> nums;

    int power = 0;
    bool is_negative = false;
    if ( x < 0 ) {
        is_negative = true;
        // x = abs(x);
    }

    while (x != 0) {
        int last_num = x % 10;

        if (x != 0) {
            nums.push_back(last_num);
            power += 1;
        }
        x /= 10;
    }

    long long reversed_num = 0;
    int idx = 0;

    power--;
    while (power >= 0)
    {
        reversed_num += pow(10, power) * nums[idx];

        idx++;
        power--;
    }

    // if (is_negative) {
    //     return -reversed_num;
    // }

    if (reversed_num > INT_MAX || reversed_num < INT_MIN) return 0;
    
    return (int)reversed_num;
}