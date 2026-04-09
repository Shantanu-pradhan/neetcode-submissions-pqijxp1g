class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = 0;
        int len = piles.size();
        sort(piles.begin(), piles.end());
        //binary search from 1 till max value
        int left = 1;
        int right = piles[len-1];
        int mid = 0;
        long long tot_hr = 0;
        while(left <= right){
            mid = (left+right)/2;
            for(int i=0; i<len; i++){
                tot_hr+=(piles[i]/mid);
                tot_hr=(piles[i]%mid)?tot_hr+1:tot_hr;
                //optimize for the loop to dont run till the end of the looop
            }
            if(tot_hr > h){
                left = mid+1;
            } else if(tot_hr <= h){
                res = mid;
                right = mid-1;
            } 
            // else {
            //      return mid;
            //  }
            tot_hr = 0;
        }
        return res;
    }
};
