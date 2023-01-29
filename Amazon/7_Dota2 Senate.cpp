/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/dota2-senate/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;
        int r,d;
        int l=senate.length();
        for(int i=0;i<l;i++){
            if(senate[i]=='R') R.push(i);
            else D.push(i);
        }
        while(!R.empty() && !D.empty()){
            r=R.front();
            d=D.front();
            R.pop();
            D.pop();
            if(r<d){
                R.push(r+l);
            }
            else{
                D.push(d+l);
            }
        }
        if(R.empty()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};