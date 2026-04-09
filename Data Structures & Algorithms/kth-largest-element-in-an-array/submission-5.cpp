class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int res = kth_largest(nums, k, 0, nums.size()-1);
        return res;
    }
    int kth_largest(vector<int>&nums, int k, int left, int right)
    {
        int p = left;
        int pivot = right;
        for(int i=left; i<right; i++){
            if(nums[i] <= nums[pivot]){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[pivot]);
        if(k == p){
            return nums[p];
        } else if(k>p){
            return kth_largest(nums, k, p+1, right);
        } else {
            return kth_largest(nums, k, left, p-1);
        }
        return -1;
    }
};
