class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        unordered_map<int, int> deleted; 
        priority_queue<int> pq;
        for (int i = 0; i < nums.size()-(k-1); i++){
            if(i == 0){
                for (int j = 0; j < k; j++){
                    pq.push(nums[i+j]);
                }
                results.push_back(pq.top());
                deleted[nums[i]]++;
                continue;
            }

            pq.push(nums[i + k - 1]);
            while(deleted.count(pq.top())){
                deleted[pq.top()]--;
                if(deleted[pq.top()] == 0){
                    deleted.erase(pq.top());
                }
                pq.pop();
            }
            results.push_back(pq.top());
            deleted[nums[i]]++;
        }
        return results;
    }
};
