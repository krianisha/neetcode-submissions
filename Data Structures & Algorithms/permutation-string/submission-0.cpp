class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0,j=0;
        int n=s2.length();
        while(j<n){
            if(j-i+1==s1.length()){
                if(check(s1,s2.substr(i,s1.length()))) return true;
                i++;
            }
            j++;
        }
        return false;
    }
    bool check(string s1, string s2){
        unordered_map<char,int>map1,map2;
        for(int i=0;i<s1.length();i++) map1[s1[i]]++;
        for(int i=0;i<s2.length();i++) map2[s2[i]]++;
        return map1==map2;

    }
};
