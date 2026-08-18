class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int>a;
      double m;
     for(int i=0;i<nums1.size();i++)
     {
         a.push_back(nums1[i]);
     } 
     for(int i=0;i<nums2.size();i++)
     {
         a.push_back(nums2[i]);
     }   
     sort(a.begin(),a.end());
     int n=a.size();
     if(n%2!=0)
     {
         m=a[n/2];
     }
     else
     {
         double z=a[n/2]+a[(n/2)-1];
         m=z/2;
     }
     return m;


    }
};
