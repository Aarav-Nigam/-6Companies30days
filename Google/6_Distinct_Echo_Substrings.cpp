/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/distinct-echo-substrings/
*/
using namespace std;
#include<vector>
#include<set>
#include<string_view>
#include<string>
#include<algorithm>
class Solution {
      // Idea:We will use 2 pointers l and r to count equal characters for different lengths of substrings (len).
    //we will traverse for all possible lens(1,to size()/2)
public:
 int distinctEchoSubstrings(string text) {
	set<string_view> res;
	const char *p = text.c_str();
	for (int i=0; i<text.size(); ++i) {
		for (int len=1; i+len+len<=text.size(); ++len) {
			const string_view a(p+i    , len);
			const string_view b(p+i+len, len);
			if (a==b) {
				res.insert(a);
			}
		}
	}
	return res.size();
}
};