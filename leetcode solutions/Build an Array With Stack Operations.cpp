class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> vtr;
        vector<int> tar;
        tar.push_back(target[0]);
        for(int i=1; i<target.size(); i++) tar.push_back(target[i]-target[i-1]);
        for(int i=0; i<tar.size(); i++) {
            while(tar[i] > 0){
                vtr.push_back("Push");
                if(tar[i]!=1) vtr.push_back("Pop");
                tar[i]--;
            }
        }
        return vtr;
    }
};
