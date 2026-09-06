#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}


#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length())
        return false;

    int freq[26] = {0};

    for (char ch : s)
        freq[ch - 'a']++;

    for (char ch : t)
        freq[ch - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}


#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {

    int freq[26] = {0};

    for (char ch : s)
        freq[ch - 'a']++;

    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }

    return -1;
}


//02-09-26
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (ch == ')') {
                depth--;
            }
        }

        return maxDepth;
    }
};

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

//04-09-26

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    int freq[26] = {0};

    for (char c : s)
        freq[c - 'a']++;

    for (char c : t)
        freq[c - 'a']--;

    for (int x : freq) {
        if (x != 0)
            return false;
    }

    return true;
}


#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {

    if (s.length() != t.length())
        return false;

    int mp1[256] = {0};
    int mp2[256] = {0};

    for (int i = 0; i < s.length(); i++) {

        if (mp1[s[i]] != mp2[t[i]])
            return false;

        mp1[s[i]] = i + 1;
        mp2[t[i]] = i + 1;
    }

    return true;
}

#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {

    string ans;
    int depth = 0;

    for (char c : s) {

        if (c == '(') {
            if (depth > 0)
                ans += c;

            depth++;
        }
        else {
            depth--;

            if (depth > 0)
                ans += c;
        }
    }

    return ans;
}

//05-09-26

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    if (t.length() > s.length())
        return "";

    int freq[256] = {0};

    for (char c : t)
        freq[c]++;

    int left = 0;
    int count = t.length();

    int start = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < s.length(); right++) {

        if (freq[s[right]] > 0)
            count--;

        freq[s[right]]--;

        while (count == 0) {

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            freq[s[left]]++;

            if (freq[s[left]] > 0)
                count++;

            left++;
        }
    }

    if (minLen == INT_MAX)
        return "";

    return s.substr(start, minLen);
}

#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    vector<int> ans;

    if (p.length() > s.length())
        return ans;

    int need[26] = {0};
    int window[26] = {0};

    for (char c : p)
        need[c - 'a']++;

    int k = p.length();

    for (int i = 0; i < s.length(); i++) {

        window[s[i] - 'a']++;

        if (i >= k)
            window[s[i - k] - 'a']--;

        if (i >= k - 1) {

            bool same = true;

            for (int j = 0; j < 26; j++) {
                if (need[j] != window[j]) {
                    same = false;
                    break;
                }
            }

            if (same)
                ans.push_back(i - k + 1);
        }
    }

    return ans;
}

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {

    int freq[256] = {0};

    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.length(); right++) {

        freq[s[right]]++;

        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

    stringstream ss(s);

    vector<string> words;
    string word;

    while (ss >> word)
        words.push_back(word);

    reverse(words.begin(), words.end());

    string ans;

    for (int i = 0; i < words.size(); i++) {

        if (i > 0)
            ans += " ";

        ans += words[i];
    }

    return ans;
}

#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {

    string ans;
    int depth = 0;

    for (char c : s) {

        if (c == '(') {
            if (depth > 0)
                ans += c;

            depth++;
        }
        else {
            depth--;

            if (depth > 0)
                ans += c;
        }
    }

    return ans;
}

//06-09-26
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int freq[26] = {0};

    int left = 0;
    int maxFreq = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {

        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // characters that need replacement
        int changes = (right - left + 1) - maxFreq;

        while (changes > k) {
            freq[s[left] - 'A']--;
            left++;

            changes = (right - left + 1) - maxFreq;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {

    int write = 0;
    int i = 0;

    while (i < chars.size()) {

        char current = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == current) {
            i++;
            count++;
        }

        chars[write++] = current;

        if (count > 1) {

            string num = to_string(count);

            for (char c : num)
                chars[write++] = c;
        }
    }

    return write;
}

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {

    unordered_map<char, int> freq;

    for (char c : s)
        freq[c]++;

    vector<pair<char, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(),
         [](auto &a, auto &b) {
             return a.second > b.second;
         });

    string ans;

    for (auto &p : v) {
        ans.append(p.second, p.first);
    }

    return ans;
}

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {

    unordered_map<char, int> value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {

        if (i + 1 < s.size() &&
            value[s[i]] < value[s[i + 1]]) {

            ans -= value[s[i]];
        }
        else {
            ans += value[s[i]];
        }
    }

    return ans;
}