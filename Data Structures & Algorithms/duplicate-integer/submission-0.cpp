class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>umap(nums.size());
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        for(auto i:umap){
            if(i.second>=2) return true;
        }
        return false;
    }
};