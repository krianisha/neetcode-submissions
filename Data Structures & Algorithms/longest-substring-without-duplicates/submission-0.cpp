class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=1;
        int n=s.length();
        if(s.empty()) return 0;
        unordered_map<char,int>umap;
        int l=1;
        umap[s[0]]++;
        while(j<n){
         while(umap.find(s[j])!=umap.end()){
            umap[s[i]]--;
            if(umap[s[i]]==0) umap.erase(s[i]);;
            i++;
         }
         l=max(l,j-i+1);
         umap[s[j]]++;
         j++;
        }
        return l;
    }
};
