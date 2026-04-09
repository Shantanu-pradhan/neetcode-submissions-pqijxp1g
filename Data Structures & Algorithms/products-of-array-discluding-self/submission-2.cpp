class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pfix(n);
        vector<int>sfix(n);
        vector<int>res(n);
        pfix[0] = 1;
        sfix[n-1] = 1;
        for(int i=1; i<n; i++){
            pfix[i] = pfix[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            sfix[i] = sfix[i+1]*nums[i+1];
        }
        for(int i=0; i<n; i++){
            res[i] = pfix[i]*sfix[i];
        }
        return res;
    }
};
