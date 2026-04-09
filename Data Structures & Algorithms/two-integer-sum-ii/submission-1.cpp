class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        //vector<int>res;
        int r=numbers.size()-1;
        while(l<r){
            if(numbers[l] + numbers[r] == target)
                break;
            else if(numbers[l] + numbers[r] > target)
                r--;
            else if(numbers[l] + numbers[r] < target)
                l++;
        }
        //res.push_back(l+1);
        //res.push_back(r+1);
        //return res;
        return {l+1, r+1};
    }
};
