class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0, tmp = 0;
        int l = 0;
        int r = heights.size()-1;
        while(l < r){
            tmp = (r - l)*min(heights[l], heights[r]);
            res = max(res, tmp);
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return res;

    }
};
