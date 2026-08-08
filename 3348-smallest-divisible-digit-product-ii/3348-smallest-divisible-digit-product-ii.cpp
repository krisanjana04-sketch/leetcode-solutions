class Solution {
public:

    // Factors: 2, 3, 5, 7
    vector<int> factors(int x) {
        vector<int> f(4, 0);

        while (x % 2 == 0) {
            f[0]++;
            x /= 2;
        }

        while (x % 3 == 0) {
            f[1]++;
            x /= 3;
        }

        while (x % 5 == 0) {
            f[2]++;
            x /= 5;
        }

        while (x % 7 == 0) {
            f[3]++;
            x /= 7;
        }

        return f;
    }

    /*
     * Minimum number of digits needed to provide
     * a factors of 2 and b factors of 3.
     *
     * Digits:
     * 2 -> 2
     * 3 -> 3
     * 4 -> 2^2
     * 6 -> 2 * 3
     * 8 -> 2^3
     * 9 -> 3^2
     */
    int min23(int a, int b) {
        int ans = 1000000000;

        // Number of 6s used.
        for (int six = 0; six <= min(a, b); six++) {

            int twos = a - six;
            int threes = b - six;

            int digits = six;

            // Remaining 2s: use 8 as much as possible.
            digits += twos / 3;

            if (twos % 3 != 0)
                digits++;

            // Remaining 3s: use 9 as much as possible.
            digits += threes / 2;

            if (threes % 2 != 0)
                digits++;

            ans = min(ans, digits);
        }

        return ans;
    }

    /*
     * Can the required factors be supplied
     * using at most len digits?
     */
    bool possible(const vector<int>& need, int len) {

        if (len < 0)
            return false;

        int d23 = min23(need[0], need[1]);

        return d23 + need[2] + need[3] <= len;
    }

    /*
     * Build the lexicographically smallest
     * zero-free string of exactly len digits.
     */
    string build(vector<int> need, int len) {

        string ans;

        for (int pos = 0; pos < len; pos++) {

            bool found = false;

            for (int d = 1; d <= 9; d++) {

                vector<int> f = factors(d);

                vector<int> rem(4);

                for (int j = 0; j < 4; j++) {
                    rem[j] = max(0, need[j] - f[j]);
                }

                int left = len - pos - 1;

                if (possible(rem, left)) {

                    ans += char('0' + d);
                    need = rem;
                    found = true;

                    break;
                }
            }

            if (!found)
                return "";
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        /*
         * Factor t.
         */
        vector<int> need(4, 0);

        while (t % 2 == 0) {
            need[0]++;
            t /= 2;
        }

        while (t % 3 == 0) {
            need[1]++;
            t /= 3;
        }

        while (t % 5 == 0) {
            need[2]++;
            t /= 5;
        }

        while (t % 7 == 0) {
            need[3]++;
            t /= 7;
        }

        /*
         * If t contains any other prime factor,
         * no digit product can be divisible by t.
         */
        if (t != 1)
            return "-1";

        int n = num.size();

        /*
         * Prefix factor counts.
         */
        vector<array<int, 4>> pref(n + 1);

        for (int j = 0; j < 4; j++)
            pref[0][j] = 0;

        vector<int> zeroPrefix(n + 1, 0);

        for (int i = 0; i < n; i++) {

            pref[i + 1] = pref[i];

            int d = num[i] - '0';

            if (d == 0) {

                zeroPrefix[i + 1] =
                    zeroPrefix[i] + 1;

            } else {

                zeroPrefix[i + 1] =
                    zeroPrefix[i];

                vector<int> f = factors(d);

                for (int j = 0; j < 4; j++)
                    pref[i + 1][j] += f[j];
            }
        }

        /*
         * Check num itself.
         */
        if (zeroPrefix[n] == 0) {

            bool good = true;

            for (int j = 0; j < 4; j++) {

                if (pref[n][j] < need[j]) {
                    good = false;
                    break;
                }
            }

            if (good)
                return num;
        }

        /*
         * Try to create a valid number
         * with the SAME length.
         *
         * Change the rightmost possible position.
         */
        for (int pos = n - 1; pos >= 0; pos--) {

            /*
             * Prefix before pos must contain no zero.
             */
            if (zeroPrefix[pos] != 0)
                continue;

            int oldDigit = num[pos] - '0';

            for (int d = oldDigit + 1; d <= 9; d++) {

                vector<int> f = factors(d);

                vector<int> rem(4);

                for (int j = 0; j < 4; j++) {

                    rem[j] = max(
                        0,
                        need[j] -
                        pref[pos][j] -
                        f[j]
                    );
                }

                int suffixLen = n - pos - 1;

                if (!possible(rem, suffixLen))
                    continue;

                string suffix =
                    build(rem, suffixLen);

                if (suffix.empty() &&
                    suffixLen != 0)
                    continue;

                string answer =
                    num.substr(0, pos);

                answer += char('0' + d);
                answer += suffix;

                return answer;
            }
        }

        /*
         * No answer of length n.
         *
         * IMPORTANT:
         * We cannot simply use n + 1.
         *
         * The required factorization may need
         * many more digits.
         */

        int minimumLength =
            min23(need[0], need[1])
            + need[2]
            + need[3];

        int length =
            max(n + 1, minimumLength);

        /*
         * First digit cannot be zero.
         */
        for (int first = 1; first <= 9; first++) {

            vector<int> f = factors(first);

            vector<int> rem(4);

            for (int j = 0; j < 4; j++) {

                rem[j] =
                    max(0, need[j] - f[j]);
            }

            int suffixLen = length - 1;

            if (!possible(rem, suffixLen))
                continue;

            string suffix =
                build(rem, suffixLen);

            if (suffix.empty() &&
                suffixLen != 0)
                continue;

            return string(1, char('0' + first))
                   + suffix;
        }

        return "-1";
    }
};