class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zcount=0;
        vector<int>res(nums.size());
        for(int n:nums){
            if(n!=0){
                prod*=n;
            } else {
                zcount++;
            }
        }
        if(zcount>1){
            return vector<int>(nums.size(),0);
        }
        for(int i=0; i<nums.size(); i++) {
            if(zcount > 0){
                res[i] = (nums[i] != 0) ? 0 : prod;
            } else {
                res[i] = prod/nums[i];
            }
        }
        return res;
    }
};
