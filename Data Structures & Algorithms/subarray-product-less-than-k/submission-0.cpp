class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        long product = 1;
        int res = 0;
        for(int r=0; r<nums.size(); r++){
            product = product*nums[r];
            while(product >= k && l<=r){
                product = product/nums[l];
                l++;
            }
            res = res+r-l+1;
        }
        return res;
    }
};