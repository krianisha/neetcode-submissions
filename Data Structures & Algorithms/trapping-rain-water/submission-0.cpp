class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>p(n+1);
        vector<int>s(n+1);
        p[0]=height[0];
        s[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            p[i]=max(p[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            s[i]=max(s[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(s[i],p[i])-height[i]);
        }
        return ans;
    }
};
