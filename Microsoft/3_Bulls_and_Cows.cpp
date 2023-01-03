/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/bulls-and-cows/description/
*/
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        //Initializing variables and maps for cows and bulls
        int bulls=0,cows=0;
        map<char,int> m1,m2;

        int l=secret.length();
        for(int i=0;i<l;i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            m1[secret[i]]++;
            m2[guess[i]]++;
        }
        for(auto i:m2){
            cows+=min(m1[i.first],i.second); //Calculating values of cows by traversing through its map   (taking min)
        }
        cows-=bulls; //The above traversal also counted the no. of bulls , so we have to subtract it.

        string ans="",cow=to_string(cows),bull=to_string(bulls); // to_string function in string library
        ans+=bull;
        ans+="A";
        ans+=cow;
        ans+="B";
        
        return ans;
    }
};