class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(auto cnt:tasks){
            count[cnt-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0; i<count.size(); i++){
            if(count[i] > 0){
                pq.push(count[i]);
            }
        }
        int time = 0;
        queue<pair<int, int>>wq;
        while(!wq.empty() || !pq.empty()){
            time++;
            if(pq.empty()){
                time = wq.front().second;
            } else {
                int cnt = pq.top()-1;
                pq.pop();
                if(cnt > 0){
                    wq.push({cnt, time+n});
                }
            }
            if(!wq.empty() && wq.front().second == time){
                pq.push(wq.front().first);
                wq.pop();
            }
        }
        return time;
    }
};
