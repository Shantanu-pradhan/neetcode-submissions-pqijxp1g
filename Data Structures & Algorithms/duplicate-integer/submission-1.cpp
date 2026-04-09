class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int>cvector;
        for(int val:nums){
            if(find(cvector.begin(), cvector.end(), val) == cvector.end()){
                cvector.push_back(val);
            } else {
                return true;
            }
        }
        return false;
    }
};
