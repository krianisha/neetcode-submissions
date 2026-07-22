class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        unordered_map<char,int>umap;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++)
            umap[s[i]]++;
          for(int i=0;i<t.length();i++){
            umap[t[i]]--;
            if(umap[t[i]]<0) return false;
          }   
        return true;       
    }
};
