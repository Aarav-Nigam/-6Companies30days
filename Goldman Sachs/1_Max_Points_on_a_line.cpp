/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/max-points-on-a-line/
*/
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
//A simple question that can be solved by brute force
//Calculate slope from one point to all point =>map the slope =>store the max=>clear the map
// Repeat the above for all points
    double slope(vector<int> a,vector<int> b){
        if(a[0]==b[0]) return 1000000.0;
        else {
            return (1.0*(b[1]-a[1]))/(b[0]-a[0]);
        }
    }
    int maxPoints(vector<vector<int>>& points) {
        map<double,int> m;
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double a=slope(points[i],points[j]);
                m[a]++;
                ans=max(ans,m[a]);
            }
            m.clear();
        }
        return ans+1;
    }
};