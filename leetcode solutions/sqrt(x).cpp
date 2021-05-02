class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        int l=0, r=x;
        int mid=0;
        int ans=0;
        
        while(l<=r){
            mid = l + (r-l)/2;
            if(mid!=0 && mid > x/mid){
                ans=mid-1;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
