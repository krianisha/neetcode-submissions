class Solution {
public:
    int hammingWeight(uint32_t n) {
        //left shift
        // int c=0;
        // for(int i=0;i<32;i++)
        // {
        //         if(n & (1<<i)){
        //             c++;
        //         }
        // }
        // return c;
        //right shift
        int count = 0;

        while(n) {
            count += n & 1;
            n = n >> 1;
        }

        return count;
    }
};