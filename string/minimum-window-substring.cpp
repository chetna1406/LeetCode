class Solution {
public:
    string minWindow(string s, string t) {
    vector<int> have(256, 0), need(256, 0);

    for (char c : t) need[c]++;

    int required = 0;
    for (int i = 0; i < 256; i++)
        if (need[i] > 0) required++;

    int formed = 0, left = 0;
    int minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
        have[s[right]]++;

        if (have[s[right]] == need[s[right]])
            formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            have[s[left]]--;
            if (have[s[left]] < need[s[left]])
                formed--;

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);


    }
};