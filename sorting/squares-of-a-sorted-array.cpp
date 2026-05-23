class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int i=0;
        int j=nums.size()-1;
        int id=nums.size()-1;
        while(i<=j){
            int leftsq= nums[i]*nums[i];
            int rightsq= nums[j]*nums[j];
            if(leftsq>rightsq){
                result[id]=leftsq;
                i++;
            }
            else{
                result[id]=rightsq;
                j--;
            }
            id--;
        }
        return result;
    }
};