class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
   int n=nums.size();
        for(int i=0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
              unordered_map<int,int>umap;
            for(int j=i+1;j<nums.size();j++){
                int target=-(nums[i]+nums[j]);
                if(umap.find(target)!=umap.end()){
                    ans.push_back({nums[i], target, nums[j]});
                    while (j + 1 < n && nums[j] == nums[j + 1])
                        j++;
                }
                umap[nums[j]]=j;
            }
        }
        return ans;
    }
};
