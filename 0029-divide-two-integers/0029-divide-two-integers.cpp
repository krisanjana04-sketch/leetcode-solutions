class Solution {
public:
int divide(int dividend, int divisor) {
if (dividend == INT_MIN && divisor == -1)
return INT_MAX;

    long long a = dividend;
    long long b = divisor;
    bool neg = (a < 0) != (b < 0);

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long ans = 0;

    while (a >= b) {
        long long temp = b;
        long long count = 1;

        while (a >= temp + temp) {
            temp = temp + temp;
            count = count + count;
        }

        a = a - temp;
        ans = ans + count;
    }

    if (neg)
        ans = -ans;

    return ans;
}

};