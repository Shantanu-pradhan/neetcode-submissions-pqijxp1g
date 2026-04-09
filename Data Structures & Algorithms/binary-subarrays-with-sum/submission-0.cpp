class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = find_sarray(nums, goal) - find_sarray(nums, goal-1);
        return res;
    }

    int find_sarray(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int count = 0;
        int sum = 0;
        int l=0;
        for(int r=0; r<nums.size(); r++){
            sum = sum+nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
};