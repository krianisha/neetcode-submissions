class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> umap;

        umap[nums[0]] = 0;

        for(int i = 1; i < nums.size(); i++) {

            if(umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }

            umap[nums[i]] = i;
        }

        return {-1, -1};
    }
};