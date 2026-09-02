class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of every character
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Store {character, frequency}
        vector<pair<char, int>> arr;

        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        // Step 3: Sort by frequency in decreasing order
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 4: Build answer
        string ans = "";

        for (auto &p : arr) {

            char ch = p.first;
            int count = p.second;

            while (count--) {
                ans += ch;
            }
        }

        return ans;
    }
};