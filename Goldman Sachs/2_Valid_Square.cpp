/*
Name:Aarav Nigam
https://leetcode.com/problems/valid-square/
*/
/*
Making a set of length of side and diagonal
if set size = 2 
it is a square
*/
#include<vector>
#include<math.h>
#include<set>
using namespace std;
class Solution {
public:
    double d(vector<int> a,vector<int> b){
        return sqrt(pow(a[0]-b[0],2)+pow(a[1]-b[1],2));
    }
   bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<double> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
        return !s.count(0) && s.size() == 2;
    }
};