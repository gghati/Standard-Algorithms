class Solution {
public:
    int xorOperation(int n, int start) {
        int xorvar=0;
        for(int i=0; i<n; i++) {
            xorvar ^= (start + 2*i);
        }
        return xorvar;
    }
};
