class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x = 0;

        for (int num : nums) {
            x ^= static_cast<unsigned int>(num);
        }

        // Extract the rightmost set bit safely
        unsigned int bit = x & (~x + 1u);

        int a = 0, b = 0;

        for (int num : nums) {
            if (static_cast<unsigned int>(num) & bit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};