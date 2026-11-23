class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
    }
    void add(int num) {
        v.push_back(num);
    }
    int getProduct(int k) {
        int ans = 1;
        for (int i = v.size() - k; i < v.size(); i++) {
            ans *= v[i];
        }
        return ans;
    }
};
