class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int middle = 0;
        int l = 0;
        int r = 0;
        int tmp = 0;
        for(int i=0; i<numbers.size(); i++){
            l=i+1;
            r=numbers.size()-1;
            tmp = target-numbers[i];
            while(l <= r){
                middle = l+(r-l)/2;
                if(tmp == numbers[middle]){
                    return {i+1, middle+1};
                } else if(tmp > numbers[middle]){
                    l = middle+1;
                } else {
                    r = middle-1;
                }
            }

        }
        return {};
    }
};
