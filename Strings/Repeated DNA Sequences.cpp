/* 
	Repeated DNA Sequence
	https://leetcode.com/problems/repeated-dna-sequences/
*/


#include <iostream>

using namespace std;



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        int key = 0;
        unsigned hashTable[1<<20] = {0}; 
        for(int i=0; i<s.length();i++){
            
            key = (key << 2 | (s[i]+1)%5) & 0xfffff;
            if(i < 9) continue;
            
            if(hashTable[key] == 1){
                ans.push_back(s.substr(i-9,10));
            }
            
            hashTable[key]++;
        }
        
        return ans;
    }
};