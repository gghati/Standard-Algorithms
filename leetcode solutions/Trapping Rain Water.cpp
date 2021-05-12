class Solution {
public:
    int trap(vector<int> height) {
        vector<int> lmax;
        vector<int> rmax;
        
        stack<int> stk;
        
        if(height.size() <= 2) return 0;
        
        for(int i=height.size()-1; i>=0; i--) {
            if(stk.empty())
                rmax.push_back(-1);
            else {
                while(!stk.empty() && stk.top()<=height[i]) stk.pop();
                if(stk.empty()) rmax.push_back(-1);
                else rmax.push_back(stk.top());
            } 
            if(stk.empty() || stk.top()<height[i]) stk.push(height[i]);
        }
        reverse(rmax.begin(), rmax.end());
        
        while(!stk.empty()) stk.pop(); 
        
        for(int i=0; i<height.size(); i++){
            if(stk.empty())
                lmax.push_back(-1);
            else {
                while(!stk.empty() && stk.top()<=height[i]) stk.pop();
                if(stk.empty()) lmax.push_back(-1);
                else lmax.push_back(stk.top());
            }
            if(stk.empty() || stk.top()<height[i]) stk.push(height[i]);
        }
        
        int val=0; 
        for(int i=1; i<lmax.size(); i++){
            if(lmax[i]!=-1 && rmax[i]!=-1)
                val += min(lmax[i], rmax[i]) - height[i];
        }
        return val; 
    }
};
