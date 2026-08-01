class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0,j=0;
        int n=s2.length();
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s1.length();i++) mp1[s1[i]]++;
        while(j<n){
            mp2[s2[j]]++;
            if(j-i+1==s1.length()){
                if(mp1==mp2) return true;
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0) mp2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};
