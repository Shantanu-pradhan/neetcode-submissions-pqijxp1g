class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int start = 0;
        int res = -1;
        int replace = 0;
        for(int end=0; end<blocks.length(); end++){
            if(blocks[end] == 'W'){
                replace++;
            }
            if(end - start +1 == k){
                if(res == -1){
                    res = replace;
                } else {
                    res = min(replace, res);
                }
            } 
            if (end - start +1 >= k){
                if(blocks[start] == 'W'){
                    replace--;
                }
                start++;
            }
        }
        return res;
    }
};