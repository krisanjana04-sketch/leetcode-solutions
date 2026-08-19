class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            
            // If digit is less than 9,
            // just increase it by 1
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If digit is 9, make it 0
            digits[i] = 0;
        }

        // If all digits were 9
        // Example: [9,9,9] -> [1,0,0,0]
        digits.insert(digits.begin(), 1);

        return digits;
    }
};