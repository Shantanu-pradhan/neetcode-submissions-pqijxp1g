class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0;
        int grumpy_sum = 0;
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0){
                base = base+customers[i];
            }
        }
        int l=0;
        int sum = 0;
        for(int r=0; r<customers.size(); r++){
            if(grumpy[r] == 1){
                sum = sum+customers[r];
            }
            if(r-l+1 == minutes){
                grumpy_sum = max(grumpy_sum, sum);
                if(grumpy[l] == 1){
                    sum = sum-customers[l];
                }
                l++;
            }
        }
        return (base+grumpy_sum);
    }
};