/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/
#include<vector>
#include<string>
#include<math.h>
#include<set>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int l=s.length();
        set<string> m;
        for(int i=0;i<=l-k;i++){
            m.insert(s.substr(i,k));
        }
        if(m.size()==pow(2,k)) return true;
        else return false;
    }
};