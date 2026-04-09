class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>uset;
        for(auto num:nums){
            if(uset.find(num) == uset.end()){
                uset.insert(num);
            } else {
                return true;
            }
        }
        return false;
    }
};