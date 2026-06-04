class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        unordered_map<char, int>f;
        unordered_map<char, int>g;

        for(int i=0; i<n; i++)
            f[ransomNote[i]]++;

        for(int i=0; i<m; i++)
            g[magazine[i]]++;

         for(auto it : f)
        {
            if(g[it.first] < it.second)
                return false;
        }
        return true;
    }
};