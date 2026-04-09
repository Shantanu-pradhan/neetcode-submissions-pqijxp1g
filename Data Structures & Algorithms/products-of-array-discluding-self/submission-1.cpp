class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pfix(n);
        vector<int>sfix(n);
        vector<int>res(n);
        int prod = 1;
        int nziro=0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nziro++;
            }
            pfix[i]= prod*nums[i];
            prod*=nums[i];
            if(nziro > 1){
                return vector<int>(n, 0);
            }
        }
        prod = 1;
        for(int i=n-1; i>=0; i--){
            sfix[i] = nums[i]*prod;
            prod *=nums[i];

        }
        res[0] = sfix[1];
        res[n-1] = pfix[n-2];
        for(int i=1; i<n-1; i++){
            res[i] = pfix[i-1]*sfix[i+1];
        }
        return res;
    }
};
