class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=INT_MIN;
        int l=0,r=heights.size()-1;
        while(l<r){
            int h=min(heights[l],heights[r]);
            int b=r-l;
            maxi=max(maxi,h*b);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return maxi;
    }
};
