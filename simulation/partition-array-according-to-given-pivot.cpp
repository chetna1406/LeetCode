class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> left, right, mid; //3 array to store less than, equal to & greater
        for(int x : nums)
        {
            if(x<pivot)
            left.push_back(x);
            if(x==pivot)
            mid.push_back(x);
            if(x>pivot)
            right.push_back(x);
        }

        vector<int>res;

        for(int x : left)
        res.push_back(x);

        for(int x : mid)
        res.push_back(x);

        for(int x : right)
        res.push_back(x);

        return res;

    }
};