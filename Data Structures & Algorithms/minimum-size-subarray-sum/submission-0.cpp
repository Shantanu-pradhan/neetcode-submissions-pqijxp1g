class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int min_length = -1;
        int sum = 0;
        for(int r=0; r<nums.size(); r++){
            sum = sum+nums[r];
            while(sum >= target){
                if(r-l+1 < min_length || (min_length == -1)){
                    min_length = r-l+1;
                }
                sum = sum-nums[l];
                l++;
            }
        }
        return (min_length == -1)?0:min_length;
    }
};