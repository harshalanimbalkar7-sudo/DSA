
class Solution {
public:
    void backtrack(string& num, int target, int index,
                   string expr, long long value,
                   long long prev,
                   vector<string>& ans) {

        // All digits have been used
        if (index == num.size()) {
            if (value == target) {
                ans.push_back(expr);
            }
            return;
        }

        long long curr = 0;

        // Try every possible number starting at index
        for (int i = index; i < num.size(); i++) {

            // Leading zeros are not allowed
            if (i > index && num[index] == '0') {
                break;
            }

            curr = curr * 10 + (num[i] - '0');

            string part = num.substr(index, i - index + 1);

            // First number: no operator before it
            if (index == 0) {
                backtrack(num, target, i + 1,
                          part, curr, curr, ans);
            }
            else {
                // Try +
                backtrack(num, target, i + 1,
                          expr + "+" + part,
                          value + curr, curr, ans);

                // Try -
                backtrack(num, target, i + 1,
                          expr + "-" + part,
                          value - curr, -curr, ans);

                // Try *
                backtrack(num, target, i + 1,
                          expr + "*" + part,
                          value - prev + prev * curr,
                          prev * curr, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        backtrack(num, target, 0, "", 0, 0, ans);

        return ans;
    }
};
