class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0;
        int res = -1;
        int wcount = 0;
        for(int r=0; r<blocks.length(); r++){
            if(blocks[r] == 'W'){
                wcount++;
            }
            if(r-l+1 == k){
                if(res == -1){
                    res = wcount;
                } else {
                    res = min(res, wcount);
                }
                if(blocks[l] == 'W'){
                    wcount--;
                }
                l++;
            }
        }
        return res;
    }
};