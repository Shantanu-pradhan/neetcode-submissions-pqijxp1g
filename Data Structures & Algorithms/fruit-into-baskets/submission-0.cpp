class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>fruits_type;
        int l = 0;
        int max_fruits = 0;
        int have = 0;
        int need = 2;
        for(int r=0; r<fruits.size(); r++){
            int val = fruits[r];
            fruits_type[val]++;
            have = fruits_type.size();
            if(have <= need){
                if(r-l+1 > max_fruits){
                    max_fruits = r-l+1;
                }
            } else {
                while(have > need){
                    int val = fruits[l];
                    fruits_type[val]--;
                    if(fruits_type[val] <= 0){
                        fruits_type.erase(val);
                    }
                    have = fruits_type.size();
                    l++;
                }
            }
        }
        return max_fruits;
    }
};