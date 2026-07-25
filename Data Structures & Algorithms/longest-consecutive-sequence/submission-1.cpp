class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
           s.insert(nums[i]);
           int l=1;
         for(auto i:s){
          if(s.find(i-1)==s.end()){
            int cnt=1;
            int x=i;
            while(s.find(x+1)!=s.end()){
                cnt++;
                x++;
                
            }
            l=max(l,cnt);
          } 
         }
         return l;  
    }
};
