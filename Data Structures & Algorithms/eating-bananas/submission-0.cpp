class Solution {
public:
    
long long findtotalHour(vector<int>& piles,int mid){
        long long totalHour=0;
        for(int i=0;i<piles.size();i++){
            totalHour+=ceil((double)piles[i]/mid);
        }
        return totalHour;
    }
int minEatingSpeed(vector<int>& piles, int h) {
    int l=1,r=1e9,maxi=0,ans=0;
    for(int i=0;i<piles.size();i++) maxi=max(maxi,piles[i]);
    r=maxi;
    while(l<=r){
        int mid=(l+r)/2;
        if(findtotalHour(piles,mid)<=h){
            ans=mid;
            r=mid-1; 
        }
        else l=mid+1;
    }
    return ans;
}
};