/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/minimum-genetic-mutation/
*/
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>

using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int len=bank.size();int counter,ans=0;char a;
        map<string,int> vis;
        for(string i:bank){
            vis[i]=0;
        }
        if(vis.find(end)==vis.end()){
            return -1;
        }
        vector<char> choices={'A','C','G','T'};
        queue<string> A;
        A.push(start);
        while(!A.empty()){
            counter=A.size();
            while(counter--){
                start=A.front();
                A.pop();
                if(start==end){
                    return ans;
                }
                for(int i=0;i<8;i++){
                    a=start[i];
                    for(int j=0;j<4;j++){
                        start[i]=choices[j];
                        if(vis.find(start)!=vis.end()){
                            if(vis[start]==0){
                                vis[start]=1;
                                A.push(start);
                            }
                        }
                    }
                    start[i]=a;
                }
                
            }
            ans++;
        }
        return -1;
    }
};
