#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i]!= "+" && tokens[i]!="-" && tokens[i]!= "*" && tokens[i]!= "/" ){
                s.push(stoi(tokens[i]));
            }

            else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();

                if(tokens[i] == "+" )
                    s.push(a + b);
                if(tokens[i] == "-" )
                    s.push(a - b);
                if(tokens[i] == "*" )
                    s.push(a * b);
                if(tokens[i] == "/" )
                    s.push(a / b);
            }
        }
        return s.top();
    }
};

int main()
{
    vector<string>tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout<<s.evalRPN(tokens);
    return 0;
}