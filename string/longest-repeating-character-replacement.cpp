class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>freq;
        int left=0, res=0, maxFreq=0;
        int n=s.size();
        for(int right=0; right<n; right++){
            freq[s[right]]++;
            maxFreq=max(maxFreq, freq[s[right]]);
            while((right-left+1)-maxFreq>k){
                freq[s[left]]--;
                left++;
            }
            res= max(res, right-left+1);
        }
        return res;
    }      
};