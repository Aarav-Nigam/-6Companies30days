/*Name:Aarav Nigam
https://leetcode.com/problems/invalid-transactions/
*/
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
using namespace std;
class Solution {
public:
        vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        vector<int> index(n,0);
        map<string,vector<vector<string>>> m;
        int count=0;
        for(auto& t:transactions){
            stringstream ss(t);
            vector<string> s(4);

            int i=0;
            while(getline(ss,s[i++],','));

            if(stoi(s[2])>1000) index[count]=1;

            for(vector<string> j:m[s[0]])
                if((j[3]!=s[3]) && abs(stoi(j[1])-stoi(s[1]))<=60){
                    index[stoi(j[4])]=1;
                    index[count]=1;
                }
            m[s[0]].push_back({s[0],s[1],s[2],s[3],to_string(count++)});
        }
        vector<string> ans;
        for(int k=0;k<n;k++){
            if(index[k]) ans.push_back(transactions[k]);
        }
        return ans;
    }
};