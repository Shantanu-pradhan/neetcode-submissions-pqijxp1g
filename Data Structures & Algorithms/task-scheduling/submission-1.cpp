class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>vt(26,0);
        //count the frequency of each task
        for(char task:tasks){
            vt[task - 'A']++;
        }
        priority_queue<int>mheap;
        //Arange in the high frequency task is first
        for(int task_count:vt){
            if(task_count > 0){
                mheap.push(task_count);
            }
        }
        queue<pair<int, int>>q;
        int count = 0;
        int time = 0;
        while(!mheap.empty() || !q.empty())
        {
            time++;
            //Jump to the time of the next available wait queue if ready queue is empty
            if(mheap.empty()){
                time = q.front().second;
            } else {
                //First process the task in hand and then calculate when it will come next and accordingly push to the wait queue 
                count = mheap.top()-1;
                mheap.pop();
                if(count > 0){
                    q.push({count, time+n});
                }
            }
            //Check if anyone got expired and then push to the ready queue
            if(!q.empty() && q.front().second == time){
                mheap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
