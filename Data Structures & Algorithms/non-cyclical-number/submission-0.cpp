class Solution {
public:
    bool isHappy(int n) {
        int x = n;
        unordered_set<int> seen;

        while (x != 1) {
            if (seen.count(x))
                return false;

            seen.insert(x);

            int z = x;
            int sum = 0;

            while (z) {
                int digit = z % 10;
                sum = sum + (digit * digit);
                z = z / 10;
            }

            x = sum;
        }

        return true;
    }
};