class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minn=INT_MAX;
        for(int i=0; i<strs.size(); i++)
            minn = std::min(minn, (int)strs[i].length());
        
        int count=0;
        for(int i=0; i<minn; i++) {
            unordered_map<char, int> mp;
            for(int j=0; j<strs.size(); j++) {
                if(mp.find(strs[j][i])==mp.end()) mp.insert({strs[j][i], 1});
                else mp[strs[j][i]]++;
            }
            if(mp[strs[0][i]]!=strs.size()) break;
            count++;
        }
        
        string s;
        for(int i=0; i<count; i++)
            s+=strs[0][i];
        
        return s;
    }
};
