class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int start = 0;
        int res = -1;
        int recolour = 0;
        for(int end = 0; end<blocks.length(); end++){
            if(blocks[end] == 'W'){
                recolour++;
            }
            if(end - start +1 == k){
                res = (res == -1) ? recolour:min(res, recolour);
            }
            if(end-start+1>=k){
                if(blocks[start] == 'W'){
                    recolour--;
                }
                start++;
            }
        }
        return res;
    }
};