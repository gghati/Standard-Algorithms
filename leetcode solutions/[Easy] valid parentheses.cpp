class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp;
        mp.insert({')', '('});
        mp.insert({'}', '{'});
        mp.insert({']', '['});
        for(char si: s){
            if(si=='(' || si=='[' || si=='{') stk.push(si);
            
            if(si==')' || si==']' || si=='}') {
                if(stk.empty()) return false;
                if(stk.top() == mp[si]){
                    stk.pop();                    
                } else return false; 
            }
        }
        return stk.empty();
    }
};
