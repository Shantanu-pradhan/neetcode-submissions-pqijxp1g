class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nlen = nums.size();
        vector<int> res(nlen-k+1);
        //vector<int> res;
        deque<int>entry;
        int start = 0;
        for(int end=0; end<nlen; end++){
            while(!entry.empty() && nums[entry.back()] < nums[end]){
                entry.pop_back();
            }
            entry.push_back(end);
            if(entry.front() < start){
                entry.pop_front();
            }
            if(end+1 >= k){
                //res.insert(start, entry.front());
                res[start] = nums[entry.front()];
                start++;
            }
        }
        return res;
    }
};