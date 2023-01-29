/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/generate-random-point-in-a-circle/
*/
#include<bits/stdc++.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
using namespace std;
class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;x=x_center;y=y_center;
    }
    
    vector<double> randPoint() {
        double ang = (double)rand()/RAND_MAX*2*M_PI,
            hyp = sqrt((double)rand()/RAND_MAX)*r,
            dx = cos(ang) * hyp,
            dy = sin(ang) * hyp;
        return vector<double>{x + dx,y+ dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */