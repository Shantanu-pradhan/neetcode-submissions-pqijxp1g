class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>vcount(26, 0);
        for(char task:tasks){
            vcount[task-'A']++;
        }
        priority_queue<int>pq;
        for(int n:vcount){
            if(n > 0){
                pq.push(n);
            }
        }
        queue<pair<int, int>>rq;
        int time = 0;
        while(!rq.empty() || !pq.empty()){
            time++;
            if(pq.empty()){
                time = rq.front().second;
            } else {
                int count = pq.top()-1;
                pq.pop();
                if(count > 0){
                    rq.push({count, time+n});
                }
            }
            if(!rq.empty() && rq.front().second == time){
                pq.push(rq.front().first);
                rq.pop();
            }
        }
        return time;
    }
};
