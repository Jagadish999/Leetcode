class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = std::abs((long long)dividend);
        long long dvs = std::abs((long long)divisor);

        long long quotient = 0;

        // Subtract powers of 2 of divisor
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        // Determine sign
        if ((dividend < 0) != (divisor < 0))
            quotient = -quotient;

        return (int)quotient;
    }
};


int main() {

    return 0;
}