class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mp;

        for(char ch : t)
            mp[ch]++;

        int count = mp.size();
        int i = 0, j = 0;
        int start = 0, minlen = INT_MAX;

        while(j < s.length()){

            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }

            while(count == 0){

                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    start = i;
                }

                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        count++;
                }

                i++;
            }

            j++;
        }

        if(minlen == INT_MAX)
            return "";

        return s.substr(start, minlen);
    }
};