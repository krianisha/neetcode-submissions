class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++) umap[nums[i]]++;
        priority_queue<pair<int,int>>pq;
        for(auto i:umap){
          pq.push({i.second,i.first});
        }
        vector<int>ans;
        
            while(k--){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        
        return ans;
    }
};
