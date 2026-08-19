class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, set<int>> mp;

        // Store reserved seats row-wise
        for (auto seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        // Initially, every row can fit 2 groups
        int ans = 2 * n;

        // Check only rows having reserved seats
        for (auto row : mp) {
            
            int r = row.first;
            set<int> s = row.second;

            // We assumed 2 groups for this row.
            // Now find out how many groups are actually possible.
            int groups = 0;

            // Check seats 2,3,4,5
            if (s.count(2) == 0 &&
                s.count(3) == 0 &&
                s.count(4) == 0 &&
                s.count(5) == 0) {
                
                groups++;
            }

            // Check seats 6,7,8,9
            if (s.count(6) == 0 &&
                s.count(7) == 0 &&
                s.count(8) == 0 &&
                s.count(9) == 0) {
                
                groups++;
            }

            // If we cannot use left/right separately,
            // check the middle block.
            if (groups == 0) {
                
                if (s.count(4) == 0 &&
                    s.count(5) == 0 &&
                    s.count(6) == 0 &&
                    s.count(7) == 0) {
                    
                    groups = 1;
                }
            }

            // This row was already counted as 2
            // in ans, so remove its old contribution.
            ans -= 2;

            // Add the actual number of groups.
            ans += groups;
        }

        return ans;
    }
};