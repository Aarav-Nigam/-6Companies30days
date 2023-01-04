/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/
#include <vector>
#include<queue>
#include<limits.h>
using namespace std;

//Simple Djstra Algorithm
class Solution {
private:
    int M=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>> G(n);
       for(auto i:roads){
           G[i[0]].push_back({i[1],i[2]});
           G[i[1]].push_back({i[0],i[2]});
       }
       vector<long> dist(n,LONG_MAX);
       vector<int> path(n,0);
       priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
       pq.push({0,0});
       dist[0]=0;
       path[0]=1;
       while(!pq.empty()){
           pair<long,int> t=pq.top();
           pq.pop();
           for(auto i:G[t.second]){
               long vert=i.first;
               long edge=i.second;
               if(dist[vert]>dist[t.second]+edge){
                   dist[vert]=dist[t.second]+edge;
                   pq.push({dist[vert],vert});
                   path[vert]=path[t.second]%M;
               }
               else if(dist[vert] == t.first + edge) {
                    path[vert] += path[t.second];
                    path[vert] %= M;
                }
           }
       }
       return path[n-1];
    }
};