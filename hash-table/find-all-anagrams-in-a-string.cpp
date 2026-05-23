class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26,0), have(26,0);
        vector<int> ans;

        for(char c : p) need[c-'a']++;

        int required = 0;
        for(int i=0;i<26;i++)
            if(need[i] > 0) required++;

        int matches = 0, left = 0;

        for(int right = 0; right < s.size(); right++) {
            int idx = s[right]-'a';
            have[idx]++;

            if(have[idx] == need[idx])
                matches++;

            if(right - left + 1 > p.size()) {
                int lidx = s[left]-'a';
                if(have[lidx] == need[lidx])
                    matches--;
                have[lidx]--;
                left++;
            }

            if(right - left + 1 == p.size() && matches == required)
                ans.push_back(left);
        }
        return ans;
    }
};