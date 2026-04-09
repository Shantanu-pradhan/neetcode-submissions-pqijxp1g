class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        int res = findkth(nums, 0, nums.size()-1, k);
        return res;
    }

    int findkth(vector<int>&nums, int left, int right, int k)
    {
        int pivot = left;
        for(int i=left; i<=right; i++)
        {
            if(nums[i] < nums[right]){
                swap(nums[i], nums[pivot]);
                pivot++;
            }
        }
        swap(nums[pivot], nums[right]);
        if(pivot < k){
            return findkth(nums, pivot+1, right, k);
        } else if(pivot > k){
            return findkth(nums, left, pivot-1, k);
        } else {
            return nums[pivot];
        }
        return -1;
    }
};
