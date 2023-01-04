/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/longest-happy-prefix/description/
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
public:
/*Solving this question requires knowledge of KMP algorithm */
    vector<int> lps(string& word){
        vector<int> lp(word.length(), 0);
        int index = 0;
        for(int i = 1; i < word.length();)
        {
            if(word[i] == word[index])
            {
                index++;
                lp[i] = index;
                i++;
            }
            else
            {
                if(index != 0)
                    index = lp[index-1];
                else
                    i++;
            }
        }
        
        return lp;
    }
    
    string longestPrefix(string s) {
        vector<int> lp = lps(s);
        
        return s.substr(0, lp.back());
    }
};