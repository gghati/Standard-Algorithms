class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int t=32;
        while(t--){
            int f = 1 << t;
            if((n&f)!=0) count++;
        }
        return count; 
    }
};
