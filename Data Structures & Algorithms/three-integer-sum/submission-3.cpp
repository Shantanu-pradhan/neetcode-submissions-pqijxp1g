class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int left = 0;
        int right = 0;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] > 0){
                break;
            }
            left = i+1;
            right = nums.size()-1;
            while(left < right){
                sum = nums[i]+nums[left]+nums[right];
                if(sum > 0){
                    right = right-1;
                } else if(sum<0){
                    left = left+1;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }

        }
        return res;
    }
};
