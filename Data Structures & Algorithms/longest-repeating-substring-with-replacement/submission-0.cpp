class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        unordered_map<char,int>umap;
        int i=0,j=0;
        int max_freq=0,ans=0;
        while(j<s.length()){
            umap[s[j]]++;
          max_freq=max(max_freq,umap[s[j]]);
          if(j-i+1-max_freq>k){
            umap[s[i]]--;
            i++;
          }
          ans=max(ans,j-i+1);
          j++;
        }
        return ans;
    }
};
