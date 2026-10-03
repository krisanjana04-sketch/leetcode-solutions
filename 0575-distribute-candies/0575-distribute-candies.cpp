class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;

        for (int x : candyType)
            s.insert(x);

        return min((int)s.size(), (int)candyType.size() / 2);
    }
};