class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        vector<vector<int>> freq(nums.size()+1);
        vector<int>res;
        for(auto n:nums){ //traverse accross each element of the nums vector and capture the occurance 
            count[n]++;
        }
        for(const auto &temp:count){ //For each of the frquency index enter the number of elements in the vector of vector
            freq[temp.second].push_back(temp.first);
        }
        for(int i=freq.size()-1; i>0; --i) //need to traverese accross the vector element and push the element 
        {
            if(res.size()==k) {
                break;
            }
            for(auto ve:freq[i]) {
                res.push_back(ve);
            }
        }
        return res;
    }
};

//i dont know how to traverse accross 2D vectoe and collect all the elements 
//Need to read more about the iterator 
//understanding the size part 
//
