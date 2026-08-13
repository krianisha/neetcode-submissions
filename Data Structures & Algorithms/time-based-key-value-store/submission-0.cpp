class TimeMap {
public:

    // key -> [(timestamp, value), (timestamp, value), ...]
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        // Agar key exist hi nahi karti
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>>& v = mp[key];

        int low = 0;
        int high = v.size() - 1;

        string ans = "";

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Timestamp valid hai
            if (v[mid].first <= timestamp) {

                ans = v[mid].second;

                // Ho sakta hai aur bada valid timestamp mile
                low = mid + 1;
            }
            else {
                // Timestamp bada hai, left side jao
                high = mid - 1;
            }
        }

        return ans;
    }
};