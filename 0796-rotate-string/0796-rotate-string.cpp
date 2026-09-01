class Solution {
public:
    bool rotateString(string s, string goal) {

        // Different lengths can never be rotations
        if (s.length() != goal.length()) {
            return false;
        }

        // Every rotation of s will appear in s + s
        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};