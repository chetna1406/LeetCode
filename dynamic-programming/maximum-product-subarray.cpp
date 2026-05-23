class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int maxPro=nums[0];
        int minPro=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1= nums[i];
            int v2= maxPro*nums[i];
            int v3= minPro*nums[i];
            maxPro= max(v1,max(v2,v3));
            minPro=min(v1,min(v2,v3));
            res= max(res, maxPro);
        }
        return res;
    }
};