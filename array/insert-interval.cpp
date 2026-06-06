class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {

        vector<vector<int>>res;
        int s=b[0];
        int e=b[1];
        a.push_back({s,e});

        sort(a.begin(), a.end());

        int s1=a[0][0];
        int e1=a[0][1];

        

        for(int i=1; i<a.size(); i++)
        {
            int s2=a[i][0];
            int e2=a[i][1];

            if(e1>=s2)
            {
                s1=s1;
                e1=max(e1,e2);
                continue;
            }
            res.push_back({s1,e1});
            s1=s2;
            e1=e2;
        }
        res.push_back({s1,e1});
        return res;
    }
};