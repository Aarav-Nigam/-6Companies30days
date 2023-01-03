/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;//Here we are initializing a stack to keep all the numbers

        for (string s : tokens) {//Going through all the tokens using for loop

            int l=s.length(); //Saving the first character(which will hold the sign) and length of string in variables
            char c=s[0];

            //Evaluating the equation if any arthmetic operator shows up.
            if(l==1 && c=='+'){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(a+b);
            }
            else if(l==1 && c=='-'){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b-a);
            }
            else if(l==1 && c=='*'){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(a*b);
            }
            else if(l==1 && c=='/'){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b/a);
            }

            //If it is not any arithmetic operator then directly push the number after converting it to integer using builtin function.
            else{
                st.push(stoi(s));
            }
        }

        // returning the final answer
        return st.top();
    }
};
