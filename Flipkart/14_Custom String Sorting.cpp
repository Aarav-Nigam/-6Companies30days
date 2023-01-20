/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/custom-sort-string/
*/
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
  public:
    string customSortString(string S, string T) {
        map<char, int> dir;
        for (int i = 0; i < S.size(); i++) {
            dir[S[i]] = i + 1;
        }
        sort(T.begin(), T.end(),
             [&](char a, char b) { return dir[a] < dir[b]; });
        return T;
    }
};