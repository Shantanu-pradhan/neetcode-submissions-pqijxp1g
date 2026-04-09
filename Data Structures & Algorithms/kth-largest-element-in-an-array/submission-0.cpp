class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int right = nums.size();
        int range = right-k;
        int res = find_kth(nums, 0, right-1, range);
        return res;
    }
    int find_kth(vector<int>&nums, int left, int right, int k)
    {
        int res=0;
        int pivot = right;
        int point = left;
        for(int i=left; i<right; i++){
            if(nums[i] <= nums[pivot]){
                swap(nums[i], nums[point]);
                point++;
            }
        }
        swap(nums[point], nums[pivot]);
        if(k == point){
            return nums[point];
        } else if(point < k){
            return find_kth(nums, point+1, right, k);
        } else {
            return find_kth(nums, left, point-1, k);
        }
        return res;
    }
};
